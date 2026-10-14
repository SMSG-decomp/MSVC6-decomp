void __cdecl import_write_forward_reference(void *typeinfo,void *typeattr,wchar_t *name)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = *(int *)((int)typeattr + 0x28);
  if ((iVar1 != 0) && (iVar1 != 2)) {
    switch(iVar1) {
    case 1:
      import_text_printf(g_import_forward_refs,"struct %S;\n",name);
      return;
    case 3:
    case 4:
      import_text_puts(g_import_forward_refs,"struct __declspec(uuid(\"");
      import_write_guid_string(g_import_forward_refs,typeattr);
      if (iVar1 == 3) {
        pcVar2 = "";
      }
      else {
        pcVar2 = "dual ";
        if ((*(byte *)((int)typeattr + 0x36) & 0x40) == 0) {
          pcVar2 = "disp";
        }
      }
      import_text_printf(g_import_forward_refs,"\"))\n/* %sinterface */ %S;\n",pcVar2,name);
      return;
    case 5:
      import_text_printf(g_import_forward_refs,"struct /* coclass */ %S;\n",name);
      return;
    case 6:
      import_text_puts(g_import_forward_refs,"typedef ");
      import_write_typedesc(g_import_forward_refs,(void *)((int)typeattr + 0x3c),typeinfo,name,0);
      import_text_puts(g_import_forward_refs,";\n");
      break;
    case 7:
      import_text_printf(g_import_forward_refs,"union %S;\n",name);
      return;
    }
  }
  return;
}

