void __cdecl import_write_vartype_name(c1_il_buffer *buf,ushort vt)

{
  if ((vt & 0x4000) != 0) {
    import_text_puts(buf,"VT_BYREF|");
    vt = vt ^ 0x4000;
  }
  if ((vt & 0x2000) != 0) {
    import_text_puts(buf,"VT_ARRAY|");
    vt = vt ^ 0x2000;
  }
  switch(vt) {
  default:
    import_text_puts(buf,"VT_I2");
    return;
  case 3:
    import_text_puts(buf,"VT_I4");
    return;
  case 4:
    import_text_puts(buf,"VT_R4");
    return;
  case 5:
    import_text_puts(buf,"VT_R8");
    return;
  case 6:
    import_text_puts(buf,"VT_CY");
    return;
  case 7:
    import_text_puts(buf,"VT_DATE");
    return;
  case 8:
    import_text_puts(buf,"VT_BSTR");
    return;
  case 9:
    import_text_puts(buf,"VT_DISPATCH");
    return;
  case 10:
    import_text_puts(buf,"VT_ERROR");
    return;
  case 0xb:
    import_text_puts(buf,"VT_BOOL");
    return;
  case 0xc:
    import_text_puts(buf,"VT_VARIANT");
    return;
  case 0xd:
    import_text_puts(buf,"VT_UNKNOWN");
    return;
  case 0xe:
    import_text_puts(buf,"VT_DECIMAL");
    return;
  case 0x11:
    import_text_puts(buf,"VT_UI1");
    return;
  }
}

