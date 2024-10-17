

// Snippets written in JS, to convert into C or C++ (later).
// scanf(input a number)


function snippet_1(input) {

    const listOfStatements = [[200, "OK"], [404, "ERROR SERVER NOT FOUND"]];

    for (let index = 0; index < listOfStatements.length; index++) {
        const statementArray = listOfStatements[index];
        if (input == statementArray[0]) {
            console.log(statementArray[1]);
        }
        return 0;
    }
}