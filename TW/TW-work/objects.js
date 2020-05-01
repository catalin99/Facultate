const person={
    name:'Catalin',
    secondName:'Cosmin',
    age:19,
    greet: function () {
        console.log('Hello, I am ' + this.name);
    },

    greetNothingMore()
    {
        console.log('Hello, I have ' + this.age + ' years.');
    }
};

console.log(person);
person.greet();
person.greetNothingMore();

const hobbies = ['Games', "Handball", person]; // person will be mapped like object Object
hobbies.push(true); // arrays and objects are references so we don't violate const type.
hobbies.push(3);
hobbies.push([2,10]);
hobbies.push(2.3); //float
hobbies.push(2,3); //2 and 3
for(let hobby of hobbies)
{
    console.log(hobby);
}

var newHobbies=hobbies.map(newval => {
    return newval + ";";
})

for (i=0; i<newHobbies.length; i++)
{
    console.log(newHobbies[i]);
}

console.log("----------------------");
const testArr=['games', 'movies'];
const copiedArr=testArr.slice(); //copy function
const copiedArrNested=[testArr]; //nested array : array in array
for(let item of copiedArr)
{
    console.log(item);
}

for(let item of copiedArrNested)
{
    console.log(item); //just one item
}
console.log (copiedArrNested); //arr in arr

const copiedArrSpread=[...testArr] // Spread array test: puts all the items from the testArr inside of copiedArrSpread
//no nested array problem anymore

console.log(copiedArrSpread); //spread

const copiedPerson={...person} // Spread object test
console.log(copiedPerson); //spread on objects

const toArray = (arg1, arg2, arg3) => [arg1, arg2, arg3]; //arrow function, convert args to array

console.log(toArray(1,2,'mașină'));

const toArrayFlex = (...args) => args; //arrow function, flexible arguments, convert to array
console.log(toArrayFlex(2.7, 'car', 15551231)); //rest operator test

//spread -> pull elements or proprieties out of arrays or objects
//rest -> merge multiple arguments into an array and used in the argument list of a function