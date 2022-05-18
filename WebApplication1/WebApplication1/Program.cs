var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

app.Use( async (context,next) => {
    context.Response.ContentType = "text/plain";
    await context.Response.WriteAsync("Aoa Pakistan...\n");
    await next();
} );
app.Use(async (context, next) => {
    await context.Response.WriteAsync("Welcome to EAD\n");
    await next();
});

app.MapGet("/abc", () => "Hello World!");

app.Run();
