let user = {
    name: 'Masha',
    age: 21
};
let copyUser = {...user};


let numbers = [1,2,3];
let copyNumbers = [...numbers];


let user1 = {
    name: 'Masha',
    age: 23,
    location: {
        city: 'Minsk',
        country: 'Belarus'
    }
};
let copyUser1 = {
    ...user1,
     location: {...user1.location}
};
console.log("Мой пример номер one")
copyUser1.location.city = 'Mozyr';
console.log(copyUser1); 



let user2 = {
    name: 'Masha',
    age: 28,
    skkills: ["HTML", "CSS", "JavaScript", "React"]
};
let copyUser2 = {
    ...user2,
    skkills: [...user2.skkills]
};
console.log("Мой пример номер two");
copyUser2.skkills.push("OAIP");
console.log(copyUser2);



const array = [
    {id: 1, name: 'Vasya', group: 10},
    {id: 2, name: 'Ivan', group: 11},
    {id: 3, name: 'Masha', group: 12},
    {id: 4, name: 'Petya', group: 10},
    {id: 5, name: 'Kira', group: 11},
]
console.log("Мой еще один примерчик")
let copyArray = array.map(el => ({...el}));
console.log(copyArray);



let user4 = {
    name: 'Masha',
    age: 19,
    studies:{
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        exams:{
            maths: true,
            programming: false
        }
    }
};
let copyUser4 = {
    ...user4,
    studies: {...user4.studies,
    exams: {...user4.exams}
}
};
console.log("Мой пример")
copyUser4.studies.speciality = "POIT";
console.log(copyUser4);


/*2.Обратитесь к копии объекта user5 и измените значение свойства group на 12, 
а оценку по программированию измените на 10.*/
let user5 = {
    name: 'Masha',
    age: 22,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            { maths: true, mark: 8},
            { programming: true, mark: 4},
        ]
    }
};
let copyUser5 = {
    ...user5,
    studies: {
        ...user5.studies,
        department: {
            ...user5.studies.department
        },
        exams: {...user5.studies.exams, 
        maths: {
            ...user5.studies.exams,

        },
        programming: {
            ...user5.studies.exams,
        }
    }
    }
};
console.log("Задание под номером ДВА")
copyUser5.studies.department.group = 12;
copyUser5.studies.exams[1].mark = 10;
console.log(copyUser5);



/*3.Обратитесь к копии объекта user6 и измените имя преподавателя.*/
let user6 = {
    name: 'Masha',
    age: 21,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
        { 
		maths: true,
		mark: 8,
		professor: {
		    name: 'Ivan Ivanov ',
		    degree: 'PhD'
		    }
	    },
        { 
		programming: true,
		mark: 10,
		professor: {
		    name: 'Petr Petrov',
		    degree: 'PhD'
		    }
	    },
        ]
    }
};
let copyUser6 = {
    ...user6,
    studies: {
        ...user6.studies,
        exams: user6.studies.exams.map(exam => ({
            ...exam,
            professor: {...exam.professor},
        }))
    }
};
console.log("Задание под номером ТРИ")
copyUser6.studies.exams[0].professor.name = "Vika Evseenko";
console.log(copyUser6);




/*4.Обратитесь к копии объекта user7 и измените количество страниц 
на 3 для статьи “About CSS” преподавателя Petr Ivanov.*/
let user7 = {
    name: 'Masha',
    age: 20,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            { 
		maths: true,
		mark: 8,
		professor: {
		    name: 'Ivan Petrov',
		    degree: 'PhD',
		    articles: [
                        {title: "About HTML", pagesNumber: 3},
                        {title: "About CSS", pagesNumber: 5},
                        {title: "About JavaScript", pagesNumber: 1},
                    ]
		}
	    },
        { 
		programming: true,
		mark: 10,
		professor: {
		    name: 'Petr Ivanov',
		    degree: 'PhD',
		    articles: [
                        {title: "About HTML", pagesNumber: 3},
                        {title: "About CSS", pagesNumber: 5},
                        {title: "About JavaScript", pagesNumber: 1},
                    ]
		    }
	    },
        ]
    }
};
let copyUser7 = {
    ...user7,
    studies: {
        ...user7.studies,
        department: {
            ...user7.studies.exams.map(exam => ({
                ...exam,
                professor: {
                    ...exam.professor,
                    articles: exam.professor.articles.map(article => ({...article}))
                }
            }))
        }

    }
};
console.log("Задание под номером ЧЕТЫРЕ");
copyUser7.studies.exams[1].professor.articles[1].pagesNumber = 3;
console.log(copyUser7);



/*5.Замените все сообщения в объекте store на “Hello”.*/
let store ={
    state: {
        profilePage:{
            posts:[
                {id: 1, massage: 'Hi', likesCount: 12},
                {id: 2, message: 'By', likesCount: 1},
            ],
            newPostText: 'About me',
        },
        dialogsPage: {
            dialogs: [
                {id: 1, name: 'Valera'},
                {id: 2, name: 'Andrey'},
                {id: 3, name: 'Sasha'},
                {id: 4, name: 'Viktor'},
            ],
            messages:[
                {id: 1, message: 'hi'},
                {id: 2, message: 'hi hi'},
                {id: 3, message: 'hi hi hi'},
            ],
        },
        sidebar:[],
    },
}

let copeStore = {
    state: {
        ...store.state,
        profilePage: {
            ...store.state.profilePage,
            posts: store.state.profilePage.posts.map(post => ({ ...post })),
        },
        dialogsPage: {
            ...store.state.dialogsPage,
            dialogs: store.state.dialogsPage.dialogs.map(dialog => ({ ...dialog })),
            messages: store.state.dialogsPage.messages.map(message => ({ ...message })),
        },
        sidebar: [...store.state.sidebar],
    },
};
console.log("Задание под номером ПЯТЬ")
copeStore.state.dialogsPage.messages = copeStore.state.dialogsPage.messages.map(function(m){
    return m = {id: m.id, message: "Hello"};
});
console.log(copeStore);



console.log("Задание под номером ОДИН");
console.log(user);
console.log(numbers);
console.log(user1);
console.log(user2);
console.log(user4);
console.log(user5);
console.log(user6);
console.log(user7);
console.log(store);