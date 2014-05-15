function referralConverted(params, context, done) {
  var admin = context.getAppAdminContext();
  
  // create an object in an app scope bucket named 'triggered_objects'
  var obj = admin.bucketWithName("triggered_objects").createObject();
  obj.set("test1", "value1");
  obj.save({
    success: function(targetObj) {
      done(0);
    },
    failure: function(targetObj, error) {
      done(1);
    }
  });
}