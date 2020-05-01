var name = "Max";
console.log('valoarea este ' + name);
console.log(`dddd
zzzz`);
console.log(`${name}`);
var age = 29;
var hasHobbies = true;

const variable = /*function*/ (a, b)=>{
    return a+b;
};

function toString(userName, userAge, userHobbies, fn) {
    this.newvar=13;

    console.log(fn(this.newvar,17));
    return (
         13 + '' +  25 + '1333');
        
}

var final = toString(name, age, hasHobbies, variable);
console.log(final);

const addRandom = () => 1+3;
console.log(addRandom());
