void __cdecl class_declare_deleting_destructors_if_dtor(c1_symbol *cls)

{
  c1_symbol *pcVar1;
  byte bVar2;
  c1_type *pcVar3;
  
  if ((((((cls->detail).cls)->implicit_state41 & 0x10) == 0) &&
      (pcVar1 = class_find_member_function(cls,g_name_dtor), pcVar1 != (c1_symbol *)0x0)) &&
     (pcVar3 = (c1_type *)&pcVar1->name, pcVar3 != (c1_type *)0x0)) {
    bVar2 = pcVar1->kind & 0x1f;
    if (((bVar2 != 7) && (bVar2 != 8)) && ((bVar2 != 6 && ((pcVar1->kind & 0x1f) != 0x1a)))) {
      pcVar3 = pcVar1->type;
    }
    if (pcVar3 != (c1_type *)0x0) {
      pcVar1 = (c1_symbol *)&pcVar3[-1].extra;
      if ((*(byte *)&pcVar3[-1].extra & 0x1f) == 0x1a) {
        pcVar1 = *(c1_symbol **)pcVar3->debug_index;
      }
      class_declare_deleting_destructors(cls,pcVar1);
    }
  }
  return;
}

