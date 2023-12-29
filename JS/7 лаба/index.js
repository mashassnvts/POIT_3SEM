/*1.Создайте объект products={}, в котором хранится весь имеющийся товар.  
Весь товар разделен на категории, одна из них «Обувь», которая в свою очередь делится на виды «Ботинки», «Кроссовки», «Сандалии». 
О каждой паре обуви хранится следующая информация: уникальный номер товара, размер обуви, цвет, цена. */
products = {
    shoes: {
        boots: [
            {id: 1, size: 38, color: "Red", price: 190},
            {id: 2, size: 42, color: "Blue", price: 123},
            {id: 3, size: 38, color: "Red", price: 130}
        ],
        sneakers: [
            {id: 4, size: 38, color: "Red", price: 190},
            {id: 5, size: 42, color: "Red", price: 123},
            {id: 6, size: 43, color: "Blue", price: 190}
        ],
        sandals: [
            {id: 7, size: 41, color: "Black", price: 194},
            {id: 8, size: 38, color: "Red", price: 190},
            {id: 9, size: 43, color: "Red", price: 122}
        ]
    }
}

/*2.Создайте функцию-фильтр обуви по цене в заданном диапазоне, по заданному размеру, по заданному цвету. 
Выведите номера товаров, соответствующих заданному условию (фильтру).*/
function custumFilter(shoes, more, less, size, color)
{
    let result = [];

    Object.entries(shoes).forEach(function([key, value])
    {
        let items = value;
        for(let item of items)
        {
            if((item.size == size || size == undefined)
            && (item.color == color || color == undefined)
            && (item.price >= more || more == undefined)
            && (item.price <= less || less == undefined))
            {
                result = [...result, item];
            };
        }
    })
    return result;
}

let filteredShoue = custumFilter(products.shoes,123, 190, 38, "Red");
console.log(filteredShoue);
/*3.Создайте объект newProducts аналогичный первому. Добавьте свойства   «скидка» и «стоимость товара». 
Преобразуйте свойство «цена» в свойство-аксессор таким образом, чтобы цена товара рассчитывалась с учетом стоимости и  скидки на товар.*/
newProducts = {
    shoes: {
        boots: [
            {id: 1, size: 38, color: "Red", price: 190, discount: 10, get Price(){return this.price * (1-this.discount/100)}},
            {id: 2, size: 42, color: "Blue", price: 123, discount: 15, get Price(){return this.price * (1-this.discount/100)}},
            {id: 3, size: 43, color: "Black", price: 130, discount: 11, get Price(){return this.price * (1-this.discount/100)}}
        ],
        sneakers: [
            {id: 4, size: 38, color: "Red", price: 190, discount: 12, get Price(){return this.price * (1-this.discount/100)}},
            {id: 5, size: 42, color: "Red", price: 123, discount: 13, get Price(){return this.price * (1-this.discount/100)}},
            {id: 6, size: 43, color: "Blue", price: 190, discount: 15, get Price(){return this.price * (1-this.discount/100)}}
        ],
        sandals: [
            {id: 7, size: 41, color: "Black", price: 194, discount: 20, get Price(){return this.price * (1-this.discount/100)}},
            {id: 8, size: 38, color: "Red", price: 190, discount: 16, get Price(){return this.price * (1-this.discount/100)}},
            {id: 9, size: 43, color: "Red", price: 122, discount: 17, get Price(){return this.price * (1-this.discount/100)}},
        ]
    }
}

let someShoe = newProducts.shoes.boots[0];
console.log(someShoe.Price);
/*4.Переопределите дескриптор свойств:
- «цена»: свойство можно изменять, можно перечислять, нельзя удалять;
 - “уникальный номер товара”:  нельзя изменять, можно перечислять, нельзя удалять.
*/
Object.defineProperty(someShoe, "price", 
{
    writable: true,
    enumerable: true,
    configurable: false
});

Object.defineProperty(someShoe, "id", 
{
    writable: true,
    enumerable: true,
    configurable: false
});

console.log(someShoe);
delete someShoe.id;
delete someShoe.size;
console.log(someShoe);

for(s in someShoe)
{
    console.log(s);
}
/*5.Для каждого товара (пара обуви) создайте функцию-конструктор. 
6.Создайте объект allProducts аналогичный newProducts. Каждый товар (пару обуви) создайте с помощью конструктора.*/
function Shoe(id, size, color, price, discount)
{
    this.id = id, 
    this.size = size,
    this.color = color,
    this.price = price,
    this.discount = discount
};

let allProducts = {
    shoes:{
        boots: [
            new Shoe(1, 38, "Red", 120, 10),
            new Shoe(2, 42, "Blue", 110, 15),
            new Shoe(3, 43, "Black", 130, 11)
        ],
        sneakers: [
            new Shoe(4, 38, "Black", 140, 12),
            new Shoe(5, 42, "Red", 115, 13),
            new Shoe(6, 43, "Blue", 145, 15)
        ],
        sandals: [
            new Shoe(7, 41, "Blue", 125, 20),
            new Shoe(8, 38, "Black", 105, 16),
            new Shoe(9, 43, "Red", 135, 17)
        ]
    }
}

