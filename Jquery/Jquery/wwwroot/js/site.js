$(document).ready(function () {
    $("#b1").click(function () {
        $.post("/Home/NewsPartialView", {name: "Data", rollNo: "BSEF19M007"}, function (result) {
            $("#PartialPlaceHolder").html(result);
        });
    });
});

$(document).ready(function () {
    $("#b2").click(function () {
        $("#PartialPlaceHolder").html("");
    });
});