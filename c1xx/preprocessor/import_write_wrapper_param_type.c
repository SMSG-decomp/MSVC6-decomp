void __cdecl
import_write_wrapper_param_type
          (c1_il_buffer *buf,c1_typedesc *typedesc,void *typeinfo,wchar_t *name)

{
  bool bVar1;
  bool bVar2;
  char *s;
  
  bVar1 = false;
  s = (char *)0x0;
  bVar2 = false;
  switch(typedesc->vt) {
  case 6:
  case 0xe:
    break;
  default:
    goto switchD_1049c549_caseD_7;
  case 8:
    s = g_import_bstr_type;
    goto LAB_1049c55e;
  case 0xc:
    s = g_import_variant_type;
  }
  bVar1 = true;
  import_text_puts(buf,"const ");
LAB_1049c55e:
  bVar2 = bVar1;
  if (s == (char *)0x0) {
switchD_1049c549_caseD_7:
    bVar1 = bVar2;
    import_write_typedesc(buf,typedesc,typeinfo,(wchar_t *)(~-(uint)bVar1 & (uint)name),0);
  }
  else {
    import_text_puts(buf,s);
  }
  if (bVar1) {
    import_text_puts(buf," &");
  }
  if ((name != (wchar_t *)0x0) && ((bVar1 || (s != (char *)0x0)))) {
    import_text_printf(buf," %S",name);
  }
  return;
}

