
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <string.h>
#include <mqueue.h>

constexpr int CONSUMER_NUM{5};
static sem_t *semaphore;

static constexpr uint8_t STORE_CAPACITY{8};
const char *const QUEUE_NAME{"/mqstore"};
static mq_attr attr;
static mqd_t store;

static constexpr uint8_t NAME_LEN_MAX(24);
static size_t unique_id_counter{1};

class Product
{
    size_t id;
    size_t price;
    char name[NAME_LEN_MAX];

public:
    Product() = default;
    Product(size_t _price, const char _name[NAME_LEN_MAX]) : price{_price}
    {
        id = unique_id_counter;
        unique_id_counter++;
        (void)strcpy(name, _name);
    }

    size_t get_id(void)
    {
        return id;
    }

    size_t get_price(void)
    {
        return price;
    }

    void get_name(char buffer[NAME_LEN_MAX])
    {
        (void)strcpy(buffer, name);
    }
};

/**
 * @brief Random delay from 0 to 1000.
 *
 * @return int `0-1000`
 */
int get_rand_delay(void)
{
    return ((rand() % 1000) * 1000);
}

void producer(void)
{
    store = mq_open(QUEUE_NAME, O_WRONLY | O_CREAT, 0666, &attr);
    if (store == -1)
    {
        printf("Failed to open the store as producer.\n");
    }
    else
    {
        while (true)
        {
            uint32_t rand_value{(uint32_t)rand()};

            char name[NAME_LEN_MAX] = {0};
            size_t price{rand_value % 10000};
            uint8_t rand_case = (uint8_t)(rand_value % 5);

            (void)strcpy(name, "Xaomi");
            switch (rand_case)
            {
            case (1):
                (void)strcat(name, " 9");
                break;
            case (2):
                (void)strcat(name, " 10");
                break;
            case (3):
                (void)strcat(name, " 10 Pro");
                break;
            case (4):
                (void)strcat(name, " 14 Pro Max");
                break;
            default:
                (void)strcat(name, " 12s Mini E");
            }

            Product temp{price, name};

            if (-1 == mq_send(store, (const char *)&temp, sizeof(temp), 0))
            {
                (void)sem_wait(semaphore);
                printf("Failed to add a product to the store.\n");
                (void)sem_post(semaphore);
            }

            (void)usleep(get_rand_delay());
        }
    }
}

void consumer(size_t _id)
{
    store = mq_open(QUEUE_NAME, O_RDONLY);
    if (store == -1)
    {
        printf("Failed to open the store as consumer.\n");
        std::exit(EXIT_FAILURE); // EXIT process
    }
    else
    {
        while (true)
        {
            Product temp;
            if (-1 == mq_receive(store, (char *)&temp, sizeof(Product), nullptr))
            {
                printf("Failed to get a product from the store.\n");
            }
            else
            {
                char name_buffer[NAME_LEN_MAX];
                temp.get_name(name_buffer);
                (void)sem_wait(semaphore);
                printf("\n========== Consumer %ld ===========\n", _id);
                printf("ID: %ld\n", temp.get_id());
                printf("Price: %ld\n", temp.get_price());
                printf("Name: %s\n", name_buffer);
                (void)sem_post(semaphore);
            }

            (void)usleep(get_rand_delay());
        }
    }
}

int main(void)
{
    semaphore = (sem_t *)mmap(nullptr, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
    if (semaphore == MAP_FAILED)
    {
        printf("Failed to create the semaphore.\n");
        std::exit(EXIT_FAILURE); // EXIT
    }
    if (-1 == sem_init(semaphore, 1, 1))
    {
        (void)sem_destroy(semaphore);
        printf("Failed to initialize the semaphore.\n");
        std::exit(EXIT_FAILURE); // EXIT
    }

    attr.mq_flags = 0;
    attr.mq_maxmsg = STORE_CAPACITY;
    attr.mq_msgsize = sizeof(Product);
    attr.mq_curmsgs = 0;

    for (int i = 0; i < CONSUMER_NUM; i++)
    {
        pid_t pid = fork();

        if (pid == -1)
        {
            (void)sem_wait(semaphore);
            printf("Failed to fork a child process. [%d]\n", i);
            (void)sem_post(semaphore);

            std::exit(EXIT_FAILURE); // EXIT
        }
        else if (pid == 0)
        {
            consumer(i + 1);
        }
    }

    producer();

    for (int i = 0; i < CONSUMER_NUM; i++)
    {
        (void)wait(nullptr);
    }

    (void)mq_close(store);
    (void)mq_unlink(QUEUE_NAME);
    (void)sem_destroy(semaphore);
    (void)munmap(semaphore, sizeof(sem_t));

    return EXIT_FAILURE;
}
