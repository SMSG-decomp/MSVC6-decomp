void coff_check_large_section_alignment_part(c2_list_cell *list_cell)

{
  uint uVar1;
  uint uVar2;
  c2_list_cell *pcVar3;
  int iVar4;
  
  do {
    do {
      pcVar3 = list_cell;
      if (pcVar3 == (c2_list_cell *)0x0) {
        return;
      }
      list_cell = pcVar3->next;
    } while ((list_cell == (c2_list_cell *)0x0) || ((int)((pcVar3->u04).fe)->size < 0x1000));
    uVar1 = ((list_cell->u04).fe)->size;
    uVar2 = uVar1 & 0x80001fff;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xffffe000) + 1;
    }
    iVar4 = (int)uVar2 / 2;
  } while (((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5 != 0) || ((int)uVar1 < 0x1000));
  ((list_cell->u04).fe)->size = (uVar1 - iVar4) + 0x20;
  coff_check_large_section_alignment_part(list_cell);
  return;
}

