void __cdecl
import_write_raw_param_type(c1_il_buffer *buf,void *typedesc,void *typeinfo,wchar_t *name)

{
  short sVar1;
  bool bVar2;
  
  sVar1 = *(short *)((int)typedesc + 4);
  if (((sVar1 == 6) || (sVar1 == 0xc)) || (sVar1 == 0xe)) {
    bVar2 = true;
    import_text_puts(buf,"const ");
  }
  else {
    bVar2 = false;
  }
  import_write_typedesc(buf,typedesc,typeinfo,(wchar_t *)(~-(uint)bVar2 & (uint)name),0);
  if (bVar2) {
    import_text_puts(buf," &");
    if (name != (wchar_t *)0x0) {
      import_text_printf(buf," %S",name);
    }
  }
  return;
}

