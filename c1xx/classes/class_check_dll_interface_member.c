void __thiscall class_check_dll_interface_member(c1_declarator *d,int specs)

{
  c1_symbol *pcVar1;
  byte bVar2;
  
  if ((d->spec[2] & 0xc) != 0) {
    pcVar1 = d->sym;
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = sym_new_from_declarator(d,5);
    }
    diag_error(0x1e7,pcVar1);
  }
  bVar2 = ((g_class_def_stack[g_class_depth].cls)->flags22 ^ d->spec[2]) & 4 ^ d->spec[2];
  d->spec[2] = bVar2;
  d->spec[2] = ((g_class_def_stack[g_class_depth].cls)->flags22 ^ bVar2) & 8 ^ bVar2;
  bVar2 = ((g_class_def_stack[g_class_depth].cls)->flags22 ^ *(byte *)(specs + 2)) & 4 ^
          *(byte *)(specs + 2);
  *(byte *)(specs + 2) = bVar2;
  *(byte *)(specs + 2) = ((g_class_def_stack[g_class_depth].cls)->flags22 ^ bVar2) & 8 ^ bVar2;
  return;
}

