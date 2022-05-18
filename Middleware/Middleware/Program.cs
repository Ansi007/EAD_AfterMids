var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

/*
 
This is from Middleware One\n
This is from Middleware Two\n
This is from default Middleware\n
This is from Midlleware Two Again\n
This is from Middleware One AGain\n
 */
app.Use(
    async (context, next) =>
    {
        context.Response.ContentType = "text/plain";
        await context.Response.WriteAsync("This is from Middleware One\n");
        await next();
        await context.Response.WriteAsync("This is from Middleware One Again\n");
    });

app.Use(
    async (context, next) =>
    {
        await context.Response.WriteAsync("This is from Middleware Two\n");
        await next();
        await context.Response.WriteAsync("This is from Middleware Two Again\n");
    });

app.MapGet("/", () => "This is from default Middleware\n");

app.Run();
