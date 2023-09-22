// package org.appinventor;
// import com.google.appinventor.components.runtime.HandlesEventDispatching;
// import com.google.appinventor.components.runtime.EventDispatcher;
// import com.google.appinventor.components.runtime.Form;
// import com.google.appinventor.components.runtime.Component;
// import com.google.appinventor.components.runtime.HorizontalArrangement;
// import com.google.appinventor.components.runtime.Button;
// import com.google.appinventor.components.runtime.TextBox;
// import com.google.appinventor.components.runtime.ListPicker;
// import com.google.appinventor.components.runtime.TableArrangement;
// import com.google.appinventor.components.runtime.Slider;
// import com.google.appinventor.components.runtime.BluetoothClient;
class Screen1 extends Form implements HandlesEventDispatching {
  private HorizontalArrangement place1;
  private Button angle_down;
  private TextBox text1;
  private Button angle_up;
  private ListPicker bluetooth_list;
  private Button control;
  private Button LOADING;
  private Button SHOT;
  private TableArrangement con;
  private Button front;
  private Button right;
  private Button back;
  private Button left;
  private Button stop;
  private Button disconnect;
  private Button LEAVE;
  private Slider slider1;
  private BluetoothClient BluetoothClient1;
  protected void $define() {
    this.AlignHorizontal(3);
    this.AlignVertical(2);
    this.AppName("esproject");
    this.Title("connect");
    place1 = new HorizontalArrangement(this);
    place1.Visible(false);
    angle_down = new Button(place1);
    angle_down.Height(60);
    angle_down.Width(-1030);
    angle_down.Text("角度下降");
    text1 = new TextBox(place1);
    text1.Enabled(false);
    text1.FontSize(20);
    text1.Height(60);
    text1.Width(-1020);
    text1.Hint("文字輸入盒1提示");
    angle_up = new Button(place1);
    angle_up.Height(60);
    angle_up.Width(-1030);
    angle_up.Text("角度上升");
    bluetooth_list = new ListPicker(this);
    bluetooth_list.FontBold(true);
    bluetooth_list.FontSize(20);
    bluetooth_list.Width(LENGTH_FILL_PARENT);
    bluetooth_list.Shape(1);
    bluetooth_list.Text("藍芽列表");
    bluetooth_list.Title("藍芽列表");
    control = new Button(this);
    control.FontBold(true);
    control.FontSize(20);
    control.Width(LENGTH_FILL_PARENT);
    control.Shape(1);
    control.Text("into control");
    LOADING = new Button(this);
    LOADING.FontBold(true);
    LOADING.Width(LENGTH_FILL_PARENT);
    LOADING.Shape(1);
    LOADING.Text("LOADING");
    LOADING.Visible(false);
    SHOT = new Button(this);
    SHOT.FontBold(true);
    SHOT.Width(LENGTH_FILL_PARENT);
    SHOT.Shape(1);
    SHOT.Text("SHOT");
    SHOT.Visible(false);
    con = new TableArrangement(this);
    con.Columns(3);
    con.Rows(3);
    con.Visible(false);
    front = new Button(con);
    front.Column(1);
    front.FontSize(20);
    front.Row(0);
    front.Text("前進");
    right = new Button(con);
    right.Column(2);
    right.FontSize(20);
    right.Row(1);
    right.Text("右轉");
    back = new Button(con);
    back.Column(1);
    back.FontSize(20);
    back.Row(2);
    back.Text("後退");
    left = new Button(con);
    left.Column(0);
    left.FontSize(20);
    left.Row(1);
    left.Text("左轉");
    stop = new Button(con);
    stop.Column(1);
    stop.FontSize(20);
    stop.Row(1);
    stop.Text("歸零");
    disconnect = new Button(this);
    disconnect.FontBold(true);
    disconnect.FontSize(20);
    disconnect.Width(LENGTH_FILL_PARENT);
    disconnect.Shape(1);
    disconnect.Text("斷線");
    LEAVE = new Button(this);
    LEAVE.FontBold(true);
    LEAVE.Text("離開");
    LEAVE.TextColor(0xFFFF0000);
    slider1 = new Slider(this);
    slider1.MaxValue(100);
    slider1.MinValue(0);
    slider1.ThumbEnabled(false);
    slider1.ThumbPosition(0);
    slider1.Visible(false);
    BluetoothClient1 = new BluetoothClient(this);
    EventDispatcher.registerEventForDelegation(this, "ClickEvent", "Click" );
    EventDispatcher.registerEventForDelegation(this, "InitializeEvent", "Initialize" );
    EventDispatcher.registerEventForDelegation(this, "BeforePickingEvent", "BeforePicking" );
    EventDispatcher.registerEventForDelegation(this, "AfterPickingEvent", "AfterPicking" );
    EventDispatcher.registerEventForDelegation(this, "TouchUpEvent", "TouchUp" );
    EventDispatcher.registerEventForDelegation(this, "TouchDownEvent", "TouchDown" );
  }
  public boolean dispatchEvent(Component component, String componentName, String eventName, Object[] params){
    if( component.equals(angle_up) && eventName.equals("Click") ){
      angle_upClick();
      return true;
    }
    if( component.equals(angle_down) && eventName.equals("Click") ){
      angle_downClick();
      return true;
    }
    if( component.equals(disconnect) && eventName.equals("Click") ){
      disconnectClick();
      return true;
    }
    if( component.equals(this) && eventName.equals("Initialize") ){
      thisInitialize();
      return true;
    }
    if( component.equals(bluetooth_list) && eventName.equals("BeforePicking") ){
      bluetooth_listBeforePicking();
      return true;
    }
    if( component.equals(stop) && eventName.equals("Click") ){
      stopClick();
      return true;
    }
    if( component.equals(bluetooth_list) && eventName.equals("AfterPicking") ){
      bluetooth_listAfterPicking();
      return true;
    }
    if( component.equals(angle_down) && eventName.equals("TouchUp") ){
      angle_downTouchUp();
      return true;
    }
    if( component.equals(angle_up) && eventName.equals("TouchUp") ){
      angle_upTouchUp();
      return true;
    }
    if( component.equals(front) && eventName.equals("TouchDown") ){
      frontTouchDown();
      return true;
    }
    if( component.equals(front) && eventName.equals("TouchUp") ){
      frontTouchUp();
      return true;
    }
    if( component.equals(right) && eventName.equals("TouchDown") ){
      rightTouchDown();
      return true;
    }
    if( component.equals(left) && eventName.equals("TouchUp") ){
      leftTouchUp();
      return true;
    }
    if( component.equals(control) && eventName.equals("Click") ){
      controlClick();
      return true;
    }
    if( component.equals(left) && eventName.equals("TouchDown") ){
      leftTouchDown();
      return true;
    }
    if( component.equals(right) && eventName.equals("TouchUp") ){
      rightTouchUp();
      return true;
    }
    if( component.equals(back) && eventName.equals("TouchDown") ){
      backTouchDown();
      return true;
    }
    if( component.equals(back) && eventName.equals("TouchUp") ){
      backTouchUp();
      return true;
    }
    if( component.equals(LOADING) && eventName.equals("Click") ){
      LOADINGClick();
      return true;
    }
    if( component.equals(SHOT) && eventName.equals("Click") ){
      SHOTClick();
      return true;
    }
    return false;
  }
  public void angle_upClick(){
    if(slider1.ThumbPosition()>0){
      slider1.ThumbPosition((slider1.ThumbPosition() - 1));
      text1.Text(slider1.ThumbPosition());
    }
    BluetoothClient1.SendText("D");
  }
  public void angle_downClick(){
    if(slider1.ThumbPosition()<45){
      slider1.ThumbPosition((slider1.ThumbPosition() + 1));
      text1.Text(slider1.ThumbPosition());
    }
    BluetoothClient1.SendText("U");
  }
  public void disconnectClick(){
  }
  public void thisInitialize(){
    bluetooth_list.Enabled(true);
    control.Enabled(false);
  }
  public void bluetooth_listBeforePicking(){
    bluetooth_list.Elements(BluetoothClient1.AddressesAndNames());
  }
  public void stopClick(){
    BluetoothClient1.SendText("r");
    slider1.ThumbPosition(0);
    text1.Text(slider1.ThumbPosition());
  }
  public void bluetooth_listAfterPicking(){
    if(BluetoothClient1.Connect(bluetooth_list.Selection())){
      bluetooth_list.Visible(false);
      bluetooth_list.Enabled(false);
      control.Visible(true);
      control.Enabled(true);
      disconnect.Visible(true);
    }
    if(BluetoothClient1.Available()){
      BluetoothClient1.SendText("nckues");
    }
  }
  public void angle_downTouchUp(){
    BluetoothClient1.SendText("Z");
  }
  public void angle_upTouchUp(){
    BluetoothClient1.SendText("Z");
  }
  public void frontTouchDown(){
    BluetoothClient1.SendText("F");
  }
  public void frontTouchUp(){
    BluetoothClient1.SendText("S");
  }
  public void rightTouchDown(){
    BluetoothClient1.SendText("R");
  }
  public void leftTouchUp(){
    BluetoothClient1.SendText("S");
  }
  public void controlClick(){
    bluetooth_list.Visible(false);
    control.Visible(false);
    SHOT.Visible(true);
    LOADING.Visible(true);
    con.Visible(true);
    place1.Visible(true);
    text1.Visible(true);
  }
  public void leftTouchDown(){
    BluetoothClient1.SendText("L");
  }
  public void rightTouchUp(){
    BluetoothClient1.SendText("S");
  }
  public void backTouchDown(){
    BluetoothClient1.SendText("B");
  }
  public void backTouchUp(){
    BluetoothClient1.SendText("S");
  }
  public void LOADINGClick(){
    BluetoothClient1.SendText("A");
    SHOT.Enabled(true);
  }
  public void SHOTClick(){
    BluetoothClient1.SendText("P");
    LOADING.Enabled(true);
  }
}