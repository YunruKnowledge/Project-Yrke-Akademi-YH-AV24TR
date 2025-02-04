#include <algorithm>
#include <string>
#include "greetings.h"

bool checkCase(const std::string &name);
bool checkCaseMix(const std::string *names, int count);
bool checkMultyName(const std::string &name, int &count);

void getNames(const std::string &name, std::string *names, int count);
void removeSpaces(std::string *name, int count);

std::string greet(const std::string &name)
{
    std::string respond{"Hello, "};
    int count{1};

    if (name.empty())
    {
        respond += "my friend.";
    }
    else if (checkMultyName(name, count))
    {
        std::string names[count];

        getNames(name, names, count);
        removeSpaces(names, count);

        if (!checkCaseMix(names, count))
        {
            if (!checkCase(names[0]))
            {
                respond += names[0];
                for (size_t i = 1; i < count - 1; i++)
                {
                    if (i != (names->size() - 1))
                    {
                        respond += ", ";
                    }

                    respond += names[i];
                }
                respond += " and " + names[count - 1] + ".";
            }
            else
            {
                respond = "HELLO " + names[0];
                for (size_t i = 1; i < count - 1; i++)
                {
                    if (i != (names->size() - 1))
                    {
                        respond += ", ";
                    }

                    respond += names[i];
                }
                respond += " AND " + names[count - 1] + "!";
            }
        }
        else // Need fixing
        {
            std::string cNames[count];
            int cCount{0};

            std::string lNames[count];
            int lCount{0};

            for (size_t i = 0; i < count; i++)
            {
                if (checkCase(names[i]))
                {
                    cNames[cCount++] = names[i];
                }
                else
                {
                    lNames[lCount++] = names[i];
                }
            }

            respond += lNames[0];
            for (size_t i = 1; i <= lCount - 1; i++)
            {

                if (i != lCount - 1)
                {
                    respond += ", ";
                }
                else
                {
                    respond += " and ";
                }

                respond += lNames[i];
            }
            respond += ". ";

            respond += "AND HELLO " + cNames[0];
            for (size_t i = 1; i <= cCount - 1; i++)
            {
                if (i != cCount - 1)
                {
                    respond += ", ";
                }
                else
                {
                    respond += " AND ";
                }
                respond += cNames[i];
            }

            respond += "!";
        }
    }
    else if (!checkCase(name))
    {
        respond += name + ".";
    }
    else
    {
        respond = "HELLO " + name + "!";
    }

    return respond;
}

bool checkCase(const std::string &name)
{
    return std::all_of(name.begin(), name.end(), [](unsigned char c)
                       { return std::isupper(c); });
}

bool checkCaseMix(const std::string *names, const int count)
{
    int lCase{0};
    int cCase{0};

    for (size_t i = 0; i < count; i++)
    {
        if (checkCase(names[i]))
            cCase++;
        else
            lCase++;
    }

    return (cCase > 0 && lCase > 0);
}

bool checkMultyName(const std::string &name, int &count)
{
    bool state{false};

    for (size_t i = 0; i < name.length(); i++)
    {
        if (name[i] == ',')
        {
            count++;
            state = true;
        }
    }

    return state;
}

void getNames(const std::string &name, std::string *names, int count)
{
    size_t start = 0;
    size_t commaPos;

    for (int i = 0; i < count; ++i)
    {
        commaPos = name.find(',', start);

        if (commaPos != std::string::npos)
        {
            names[i] = name.substr(start, commaPos - start);
            start = commaPos + 1;
        }
        else
        {
            names[i] = name.substr(start);
            break;
        }
    }
}

void removeSpaces(std::string *name, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        name[i].erase(std::remove(name[i].begin(), name[i].end(), ' '), name[i].end());
    }
}