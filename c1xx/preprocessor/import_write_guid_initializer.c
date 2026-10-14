void __cdecl import_write_guid_initializer(c1_il_buffer *buf,c1_guid *guid)

{
  int iVar1;
  
  import_text_printf(buf,"{0x%08x,0x%04x,0x%04x,{",guid->Data1,(uint)guid->Data2,(uint)guid->Data3);
  iVar1 = 0;
  do {
    import_text_printf(buf,"0x%02x",(uint)guid->Data4[iVar1]);
    if (iVar1 != 7) {
      import_text_putc(buf,0x2c);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  import_text_puts(buf,"}}");
  return;
}

