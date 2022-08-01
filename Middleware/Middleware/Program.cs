var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

/*
 
This is from Middleware One\n
This is from Middleware Two\n
This is from default Middleware\n
This is from Midlleware Two Again\n
This is from Middleware One AGain\n

 */



app.Use(    //To add a middleware we use "app.Use()"
    async (context, next) =>    //context object holds information of response
    {
        context.Response.ContentType = "text/plain";    //sets the type of response content
        await context.Response.WriteAsync("This is from Middleware One\n"); //write data
        await next();   //goto next middleware
        await context.Response.WriteAsync("This is from Middleware One Again\n");   //come back then write this
    });

app.Use(
    async (context, next) =>
    {
        await context.Response.WriteAsync("This is from Middleware Two\n"); //write data
        await next();   //goto next
        var query = context.Request.Query["somedata"];  //if this is in the query then show it 
        if (query.Equals("twoAgain"))
        {
            await context.Response.WriteAsync("This is from Middleware Two Again\n"); //come back write this
        }
    });

app.MapGet("/", () => "This is from default Middleware\n"); //write data, MapGet tellse there are no more 
//middle wares

app.Run();
