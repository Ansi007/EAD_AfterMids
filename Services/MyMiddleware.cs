class MyMiddleware
{
    RequestDelegate next;
    public MyMiddleware(RequestDelegate nextD){
        this.next = nextD;
    }

    public async Task Invoke(HttpContext context){
        await context.Response.WriteAsync("My Own Middlware\n");
        await next(context);
    }
}

