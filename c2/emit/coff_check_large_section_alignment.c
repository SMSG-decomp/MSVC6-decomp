void __fastcall coff_check_large_section_alignment(c2_list_cell *list)

{
  uint uVar1;
  c2_list_cell *pcVar2;
  c2_list_cell *list_cell;
  uint uVar3;
  int iVar4;
  
  if (list != (c2_list_cell *)0x0) {
    list_cell = (c2_list_cell *)coff_is_known_global_id(((list->u04).tuple)->switch_flags);
    while (pcVar2 = list, list_cell != (c2_list_cell *)0x0) {
      list_cell = pcVar2->next;
      list = list_cell;
      if ((list_cell != (c2_list_cell *)0x0) && (0xfff < (int)((pcVar2->u04).fe)->size)) {
        uVar1 = ((list_cell->u04).fe)->size;
        uVar3 = uVar1 & 0x80001fff;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xffffe000) + 1;
        }
        iVar4 = (int)uVar3 / 2;
        if (((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5 == 0) && (0xfff < (int)uVar1)) {
          ((list_cell->u04).fe)->size = (uVar1 - iVar4) + 0x20;
          coff_check_large_section_alignment_part(list_cell);
          return;
        }
      }
    }
  }
  return;
}

