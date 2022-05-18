var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

app.Use(
    async (context, next) =>
    {
        context.Response.ContentType = "text/plain";
        await context.Response.WriteAsync("This is the first middlware before next\n");
        await next();
        await context.Response.WriteAsync("This is the first middlware after next\n");
    }
);

app.Use(
    async (context, next) =>
    {
        await context.Response.WriteAsync("This is the second middleware before next\n");
        await next();
        await context.Response.WriteAsync("This is the second middleware after next\n");
    }
);

app.UseMiddleware<MyMiddleware>();
app.UseMiddleware<MySecondMiddleware>();

app.Run(
    async context => {
        if (context.Request.Query["Page"].Equals("last"))
        {
            await context.Response.WriteAsync("This is the last middlware\n");
        }
    }
);

app.Run();

//This is the first middlware before next
//This is the second middleware before next
//This is the last middlware
//This is the second middleware after next
//This is first middleware after next