int __cdecl
class_base_overlap_kind
          (char is_virtual,c1_symbol *base,c1_symbol *cls,char direct,c1_symbol **through_base)

{
  byte bVar1;
  int iVar2;
  c1_symbol *pcVar3;
  byte bVar4;
  int *piVar5;
  c1_member_iter base_iter;
  
  list_cursor_init_from_head(&base_iter.cursor,(cls->x28).members);
  base_iter.filter = 4;
  base_iter.next = (int *)0x0;
  piVar5 = base_iter.cursor.current;
  base_iter.cls = &cls->name;
  if (base_iter.cursor.valid != '\0') {
    base_iter.next = base_iter.cursor.current;
  }
  while( true ) {
    do {
      while( true ) {
        base_iter.current = base_iter.next;
        if (base_iter.current == (int *)0x0) {
          return 0;
        }
        if ((piVar5 == (int *)0x0) ||
           (base_iter.next = (void *)piVar5[1], piVar5 = base_iter.next,
           base_iter.cursor.current = base_iter.next, base_iter.next == (int *)0x0)) {
          base_iter.next = (int *)0x0;
        }
        if ((*(byte *)((int)base_iter.current + -8) & 0x1f) != 3) break;
        if ((*(void **)base_iter.current != g_name_vbptr) &&
           (*(void **)base_iter.current != g_name_vfptr)) {
          return 0;
        }
      }
    } while ((((g_compile_flags_cc & 0x100000) != 0) &&
             ((*(byte *)((int)base_iter.current + -8) & 0x1f) == 0xf)) &&
            ((*(byte *)((int)base_iter.current + 0x12) & 2) != 0));
    if ((*(byte *)((int)base_iter.current + -8) & 0x1f) != 0xf) {
      return 0;
    }
    bVar1 = *(byte *)((int)base_iter.current + 0x12);
    if (through_base != (c1_symbol **)0x0) {
      if ((bVar1 & 2) == 0) {
        pcVar3 = g_scope_vector->entries[(short)*(int *)((int)base_iter.current + 0x10)];
      }
      else {
        pcVar3 = (c1_symbol *)0x0;
      }
      *through_base = pcVar3;
    }
    bVar4 = *(byte *)((int)base_iter.current + 0x12) & 2;
    if (bVar4 == 0) {
      pcVar3 = g_scope_vector->entries[(short)*(int *)((int)base_iter.current + 0x10)];
    }
    else {
      pcVar3 = (c1_symbol *)0x0;
    }
    if ((base == pcVar3) && (((is_virtual == '\0' || (direct != '\0')) || ((bVar1 & 1) == 0))))
    break;
    if (bVar4 == 0) {
      pcVar3 = g_scope_vector->entries[(short)*(int *)((int)base_iter.current + 0x10)];
    }
    else {
      pcVar3 = (c1_symbol *)0x0;
    }
    iVar2 = class_base_overlap_kind(is_virtual,base,pcVar3,'\0',(c1_symbol **)0x0);
    if (iVar2 != 0) {
      return 2;
    }
    base_iter.next = base_iter.next;
    piVar5 = base_iter.cursor.current;
    if (direct != '\0') {
      if ((*(byte *)((int)base_iter.current + 0x12) & 2) == 0) {
        pcVar3 = g_scope_vector->entries[*(short *)((int)base_iter.current + 0x10)];
      }
      else {
        pcVar3 = (c1_symbol *)0x0;
      }
      iVar2 = class_base_overlap_kind(bVar1 & 1,pcVar3,base,'\0',(c1_symbol **)0x0);
      base_iter.next = base_iter.next;
      piVar5 = base_iter.cursor.current;
      if (iVar2 != 0) {
        return 3;
      }
    }
  }
  return 1;
}

