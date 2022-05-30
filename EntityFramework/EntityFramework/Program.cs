// See https://aka.ms/new-console-template for more information
using EntityFramework;

Console.WriteLine("Hello, World!");

var context = new EntityFrameworkPracticeContext();
Product p = new Product();
//while (true)
//{
    //p.Id = int.Parse(Console.ReadLine());
    //p.Name = Console.ReadLine();
    //p.Type = Console.ReadLine();
    //context.Products.Add(p);
   // context.SaveChanges();
//}

var prod = context.Products.First();
prod.Name = "CHANGE HOGYA";
context.Products.Add(p);    

//string as a datatype
//String as a class
//Integer as a class
//int datatype
