const person={
    name:'Catalin',
    secondName:'Cosmin',
    age:19,
    greet: function () {
        console.log('Hello, I am ' + this.name);
    }
};

const printName = (personData) => {
    console.log(personData.name);
} 

printName(person);

//destructing syntax in function
const printNameDestructing = ({name, age}) => { 
    console.log(name, age); //get fields from object by destructing the object
}

printNameDestructing(person);

const {name, secondName} = person; //destructing syntax object to variables
console.log(secondName + ' , ' + name);

const myArr = [1, 'Mama are alune', 'c', 33.21];
const [zero, one, two, three, four]=myArr; //destructing syntax array to variables
console.log(zero, one, two, three, four); // four is undefined 'cause our array has just 4 items.

