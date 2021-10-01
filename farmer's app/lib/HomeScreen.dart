import 'dart:async';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:flutter/material.dart';
import 'package:my_village/Data.dart';
import 'LogInScreen.dart';
import 'UploadData.dart';
import 'Data.dart';

// ignore: must_be_immutable
class HomeScreen extends StatefulWidget {
  String currentEmail;

  HomeScreen(this.currentEmail);

  @override
  _HomeScreenState createState() => _HomeScreenState(currentEmail);
}

class _HomeScreenState extends State<HomeScreen> {
  String currentEmail;
  List<Data> dataList = [];

  _HomeScreenState(this.currentEmail);

  FirebaseAuth auth = FirebaseAuth.instance;

  Future<void> logOut() async {
    auth.signOut().then((value) {
      Navigator.pushReplacement(
          context,
          MaterialPageRoute(
              builder: (BuildContext context) => LogInScreen()));
    });
  }


  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    DatabaseReference referenceData = FirebaseDatabase.instance.reference().child("Data");
    referenceData.once().then((DataSnapshot dataSnapShot){
      dataList.clear();
      var keys = dataSnapShot.value.keys;
      var values = dataSnapShot.value;

      for(var key in keys){
        Data data = new Data(
          values [key]["imgUrl"],
          values [key]["name"],
          values [key]["material"],
          values [key]["price"],
        );
        dataList.add(data);
      }
      setState(() {
        
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color(0xffffffff),
      appBar: AppBar(
        backgroundColor: Color(0xff00bcd4),
        title: Text("Home"),
        actions: <Widget>[
          FlatButton.icon(
              onPressed: () {
                logOut();
              },
              icon: Icon(Icons.person),
              label: Text("Log out"))
        ],
      ),
      drawer: Drawer(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.start,
          children: <Widget>[
            Container(
              width: double.infinity,
              height: 170,
              color: Color(0xffffffff),
              child: Column(
                children: <Widget>[
                  Padding(padding: EdgeInsets.only(top: 30)),
                  Image(image: AssetImage("images/DedSec_logo.png"),
                    height: 90,
                    width: 90,),
                  SizedBox(height: 10,),
                  Text(currentEmail, style: TextStyle(color: Colors.white),)
                ],
              ),
            ),
            ListTile(
              title: Text("Upload"),
              leading: Icon(Icons.cloud_upload),
              onTap: () {
                Navigator.pushReplacement(context, MaterialPageRoute(
                  builder: (BuildContext context) => UploadData()));
              },
            ),

            ListTile(
              title: Text("Price List"),
              leading: Icon(Icons.list),
              onTap: () {
                //Navigator.pushReplacement(context, MaterialPageRoute(builder: (BuildContext context) => MyFavorite()));
              },
            ),

            ListTile(
              title: Text("Weather Forecast"),
              leading: Icon(Icons.cloud),
            ),

            ListTile(
              title: Text("Loans"),
              leading: Icon(Icons.attach_money),
            ),

            ListTile(
              title: Text("Complaint"),
              leading: Icon(Icons.email),
            ) //line
          ],
        ),
      ),
      body: dataList.length== 0? Center(child: Text("No data available now",style: TextStyle(fontSize: 30),)):ListView.builder(
          itemCount: dataList.length,
          itemBuilder: (_,index){
            return CardUI(dataList[index].imgUrl, dataList[index].name,dataList[index].material,dataList[index].price,);
          }
      ),
    );
  }
  Widget CardUI(String imgUrl, String name, String material, String price) {
    return Card(
      elevation: 7,
      margin: EdgeInsets.all(15),
      color: Color(0xffff2fc3),
      child: Container(
        color: Colors.white,
        margin: EdgeInsets.all(1.5),
        padding: EdgeInsets.all(10),
        child: Column(
          children: <Widget>[
            Image.network(imgUrl, fit: BoxFit.cover, height: 100,),
            SizedBox(height: 1,),
            Text(name, style: TextStyle(color: Colors.black,
                fontSize: 25,
                fontWeight: FontWeight.bold),),
            SizedBox(height: 1,),
            Text("material:- $material"),
            SizedBox(height: 1,),
            Container(
              width: double.infinity,
              child: Text(price, style: TextStyle(
                  color: Colors.red, fontSize: 20, fontWeight: FontWeight.bold),
                textAlign: TextAlign.right,),
            ),
            SizedBox(height: 1,),
          ],
        ),
      ),
    );
  }
}

