void __cdecl import_write_dispid(c1_il_buffer *buf,int dispid)

{
  if (dispid < -0x259) {
    if (dispid == -0x25a) {
      import_text_puts(buf,"DISPID_KEYDOWN");
      return;
    }
    switch(dispid) {
    case -0x323:
      import_text_puts(buf,"DISPID_Parent");
      return;
    case -0x322:
      import_text_puts(buf,"DISPID_Object");
      return;
    case -0x321:
      import_text_puts(buf,"DISPID_Delete");
      return;
    case -800:
      import_text_puts(buf,"DISPID_Name");
      return;
    case -0x2cc:
      import_text_puts(buf,"DISPID_AMBIENT_APPEARANCE");
      return;
    case -0x2cb:
      import_text_puts(buf,"DISPID_AMBIENT_AUTOCLIP");
      return;
    case -0x2ca:
      import_text_puts(buf,"DISPID_AMBIENT_SUPPORTSMNEMONICS");
      return;
    case -0x2c9:
      import_text_puts(buf,"DISPID_AMBIENT_DISPLAYASDEFAULT");
      return;
    case -0x2c8:
      import_text_puts(buf,"DISPID_AMBIENT_SHOWHATCHING");
      return;
    case -0x2c7:
      import_text_puts(buf,"DISPID_AMBIENT_SHOWGRABHANDLES");
      return;
    case -0x2c6:
      import_text_puts(buf,"DISPID_AMBIENT_UIDEAD");
      return;
    case -0x2c5:
      import_text_puts(buf,"DISPID_AMBIENT_USERMODE");
      return;
    case -0x2c4:
      import_text_puts(buf,"DISPID_AMBIENT_TEXTALIGN");
      return;
    case -0x2c3:
      import_text_puts(buf,"DISPID_AMBIENT_SCALEUNITS");
      return;
    case -0x2c2:
      import_text_puts(buf,"DISPID_AMBIENT_MESSAGEREFLECT");
      return;
    case -0x2c1:
      import_text_puts(buf,"DISPID_AMBIENT_LOCALEID");
      return;
    case -0x2c0:
      import_text_puts(buf,"DISPID_AMBIENT_FORECOLOR");
      return;
    case -0x2bf:
      import_text_puts(buf,"DISPID_AMBIENT_FONT");
      return;
    case -0x2be:
      import_text_puts(buf,"DISPID_AMBIENT_DISPLAYNAME");
      return;
    case -0x2bd:
      import_text_puts(buf,"DISPID_AMBIENT_BACKCOLOR");
      return;
    case -0x261:
      import_text_puts(buf,"DISPID_READYSTATECHANGE");
      return;
    case -0x260:
      import_text_puts(buf,"DISPID_ERROREVENT");
      return;
    case -0x25f:
      import_text_puts(buf,"DISPID_MOUSEUP");
      return;
    case -0x25e:
      import_text_puts(buf,"DISPID_MOUSEMOVE");
      return;
    case -0x25d:
      import_text_puts(buf,"DISPID_MOUSEDOWN");
      return;
    case -0x25c:
      import_text_puts(buf,"DISPID_KEYUP");
      return;
    case -0x25b:
      import_text_puts(buf,"DISPID_KEYPRESS");
      return;
    }
  }
  else {
    switch(dispid) {
    case -0x259:
      import_text_puts(buf,"DISPID_DBLCLICK");
      return;
    case -600:
      import_text_puts(buf,"DISPID_CLICK");
      return;
    case -0x228:
      import_text_puts(buf,"DISPID_ABOUTBOX");
      return;
    case -0x227:
      import_text_puts(buf,"DISPID_DOCLICK");
      return;
    case -0x226:
      import_text_puts(buf,"DISPID_REFRESH");
      return;
    case -0x20d:
      import_text_puts(buf,"DISPID_READYSTATE");
      return;
    case -0x208:
      import_text_puts(buf,"DISPID_APPEARANCE");
      return;
    case -0x207:
      import_text_puts(buf,"DISPID_BORDERVISIBLE");
      return;
    case -0x206:
      import_text_puts(buf,"DISPID_CAPTION");
      return;
    case -0x205:
      import_text_puts(buf,"DISPID_TEXT");
      return;
    case -0x204:
      import_text_puts(buf,"DISPID_TABSTOP");
      return;
    case -0x203:
      import_text_puts(buf,"DISPID_HWND");
      return;
    case -0x202:
      import_text_puts(buf,"DISPID_ENABLED");
      return;
    case -0x201:
      import_text_puts(buf,"DISPID_FORECOLOR");
      return;
    case -0x200:
      import_text_puts(buf,"DISPID_FONT");
      return;
    case -0x1ff:
      import_text_puts(buf,"DISPID_FILLSTYLE");
      return;
    case -0x1fe:
      import_text_puts(buf,"DISPID_FILLCOLOR");
      return;
    case -0x1fd:
      import_text_puts(buf,"DISPID_DRAWWIDTH");
      return;
    case -0x1fc:
      import_text_puts(buf,"DISPID_DRAWSTYLE");
      return;
    case -0x1fb:
      import_text_puts(buf,"DISPID_DRAWMODE");
      return;
    case -0x1f9:
      import_text_puts(buf,"DISPID_BORDERWIDTH");
      return;
    case -0x1f8:
      import_text_puts(buf,"DISPID_BORDERSTYLE");
      return;
    case -0x1f7:
      import_text_puts(buf,"DISPID_BORDERCOLOR");
      return;
    case -0x1f6:
      import_text_puts(buf,"DISPID_BACKSTYLE");
      return;
    case -0x1f5:
      import_text_puts(buf,"DISPID_BACKCOLOR");
      return;
    case -500:
      import_text_puts(buf,"DISPID_AUTOSIZE");
      return;
    }
  }
  import_text_printf(buf,"0x%x",dispid);
  return;
}

