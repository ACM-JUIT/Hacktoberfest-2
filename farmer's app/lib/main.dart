import 'package:flutter/material.dart';
import 'SplashScreen.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    //implement build
    return new MaterialApp(
      //remove banner from screen
      debugShowCheckedModeBanner: false,
      home: SplashScreen(),
    );
  }
}

