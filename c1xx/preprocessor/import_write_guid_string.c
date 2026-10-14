void __cdecl import_write_guid_string(c1_il_buffer *buf,c1_guid *guid)

{
  int iVar1;
  
  import_text_printf(buf,"%08x-%04x-%04x-",guid->Data1,(uint)guid->Data2,(uint)guid->Data3);
  import_text_printf(buf,"%02x%02x-",(uint)guid->Data4[0],(uint)guid->Data4[1]);
  iVar1 = 2;
  do {
    import_text_printf(buf,"%02x",(uint)guid->Data4[iVar1]);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}

