import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'HomeScreen.dart';
import 'SignUpScreen.dart';

class LogInScreen extends StatefulWidget{
  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    return _LogInScreen();
  }

}

class _LogInScreen extends State<LogInScreen>{
  bool signInState=false;
  String email="",password="";
var _formKey=GlobalKey<FormState>();


 final FirebaseAuth auth = FirebaseAuth.instance;



  Future<void> logIn() async {

    await auth.signInWithEmailAndPassword(
        email: email.trim(), password: password).then((value){
      Navigator.push(context, MaterialPageRoute(
          builder: (BuildContext context)=>HomeScreen(value.user.email)
      ));
    });


  }


  @override
  Widget build(BuildContext context) {

    // TODO: implement build
    return Scaffold(

      backgroundColor: Color(0xffffffff),
    //change column to listview
    body: Form(
      key: _formKey,
    child: ListView(
      children: <Widget>[
        Container(
          width: double.infinity,
          height: 180,
          child: Padding(
          padding: EdgeInsets.all(20),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: <Widget>[

              SizedBox(height: 50,),

              Text("Log in",
                style: TextStyle(color: Colors.white,fontWeight: FontWeight.bold,
                fontSize: 45),
              ),

              Text("Welcome to our store",
              style: TextStyle(color: Colors.white),)

            ],
          ),
          ),

          decoration: BoxDecoration(borderRadius: BorderRadius.only(
              bottomRight: Radius.circular(150)),
              color: Color(0xff00bcd4),
    ),

        ),

        Theme(
            data: ThemeData(
              hintColor: Colors.blue
            ),
            child: Padding(padding: EdgeInsets.only(top: 50,right: 20,left: 20),
          child: TextFormField(
            validator: (value){
              if(value.isEmpty){
                return "Please enter your email";
              }else{
                email=value;
              }
              return null;
            },
            style: TextStyle(color: Colors.black),
            decoration: InputDecoration(
              labelText: "Email",
              border: OutlineInputBorder(
                borderRadius: BorderRadius.circular(15),
                borderSide: BorderSide(color: Color(0xff00bcd4),width: 1)
              ),

              disabledBorder: OutlineInputBorder(
                  borderRadius: BorderRadius.circular(15),
                  borderSide: BorderSide(color: Color(0xff00bcd4),width: 1)
              ),

              enabledBorder: OutlineInputBorder(
                  borderRadius: BorderRadius.circular(15),
                  borderSide: BorderSide(color: Color(0xff00bcd4),width: 1)
              ),

              focusedBorder: OutlineInputBorder(
                  borderRadius: BorderRadius.circular(15),
                  borderSide: BorderSide(color: Color(0xff00bcd4),width: 1)
              ),

            ),
          ),
        ),
        ),


        Theme(
          data: ThemeData(
              hintColor: Colors.blue
          ),
          child: Padding(padding: EdgeInsets.only(top: 10,right: 20,left: 20),
            child: TextFormField(
              obscureText: true,
              autocorrect: false,

              validator: (value){
                if(value.isEmpty){
                  return "Please enter your password";
                }else{
                  password=value;
                }
                return null;
              },
              style: TextStyle(color: Colors.black),
              decoration: InputDecoration(
                labelText: "Password",
                border: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(15),
                    borderSide: BorderSide(color: Color(0xff00bcd4),width: 1)
                ),

                disabledBorder: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(15),
                    borderSide: BorderSide(color: Color(0xff00bcd4),width: 1)
                ),

                enabledBorder: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(15),
                    borderSide: BorderSide(color: Color(0xff00bcd4),width: 1)
                ),

                focusedBorder: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(15),
                    borderSide: BorderSide(color: Color(0xff00bcd4),width: 1)
                ),

              ),
            ),
          ),
        ),

        SizedBox(height: 20,),
        Padding(
          padding: EdgeInsets.only(left: 20,right: 20),
        child: RaisedButton(
            onPressed: () {
              if(_formKey.currentState.validate()){
                  Future<String> check=logIn();
                  if(check!=null) {
                    Navigator.pushReplacement(context, MaterialPageRoute(
                        builder: (BuildContext context) => HomeScreen(auth.currentUser().toString())
                    ));
                  }
              }

            },
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(15),
        ),
          color: Color(0xff00bcd4),
          child: Text("Log In",style: TextStyle(color: Colors.white,
              fontWeight: FontWeight.bold,fontSize: 20),),
          padding: EdgeInsets.all(10),
        )
        ),

        SizedBox(height: 20),

        Container(
          width: double.infinity,
          height: 1,
          color: Colors.blue,
        ),




        SizedBox(height: 20,),

        Center(
        child: Column(
          children: <Widget>[
            Text("Don't have an account ?",style: TextStyle(
                color: Colors.cyan
            ),),

            FlatButton(onPressed: (){
              Navigator.of(context).pushReplacement(
                  MaterialPageRoute(builder: (BuildContext context)=> SignUpScreen())
              );

            },

              child: Column(
                children: <Widget>[
                Text("Sign Up",style: TextStyle(color: Colors.blue),),

            Container(
              width: 45,
              height: 1,
              color: Colors.blue,
            ),
                ],
            )


              )


          ],
        )

        )


      ],
    ),
    ),

    );
  }
}
