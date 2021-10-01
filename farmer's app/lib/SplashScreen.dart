import 'dart:async';
import 'package:flutter/material.dart';
import 'LogInScreen.dart';

class SplashScreen extends StatefulWidget{
  @override
  State<StatefulWidget> createState(){
    //implement create state
    return _SplashScreen();
  }
}

class _SplashScreen extends State<SplashScreen>{
  @override
  Widget build(BuildContext context){
    //implement build
    return Scaffold(
      backgroundColor: Color(0xffffffff),
      body:Center(
        child: Column(
          mainAxisAlignment : MainAxisAlignment.center,
          children: <Widget>[
            Expanded(
              flex: 2,
                child:Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: <Widget>[
                    MyImage(),
                    Text("Mera Village", style: TextStyle(fontSize:25
                    , color: Color(0xff00bcd4)),
                    )
                  ],
                )
            ),
            Expanded(
                flex:1,
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: <Widget>[
                    CircularProgressIndicator(),
                    SizedBox(height:20,),
                    Text("Ek Dukan Ek Rate", style: TextStyle(fontSize: 25,
                        fontStyle: FontStyle.italic,color: Colors.cyan))
                ],
                )
            ),

          ]
        )
      )

    );
  }
  //Navigate to login
void NavigateToLogin(){
    Timer(Duration(seconds: 5), ()=> Navigator.of(context).pushReplacement(
      MaterialPageRoute(builder: (BuildContext context)=>LogInScreen())
    )); //Timer
}

  @override
  void initState(){
    super.initState();
    NavigateToLogin();
  }
}


class MyImage extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    AssetImage image = new AssetImage("images/DedSec_logo.png");
    Image logo = new Image(image: image,width: 70, height:70);
    return logo;
  }
}