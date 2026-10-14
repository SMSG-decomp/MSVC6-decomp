void __cdecl class_sort_members(c1_symbol *cls)

{
  c1_class_record *pcVar1;
  int *piVar2;
  c1_u8 *_Base;
  c1_sym_link *pcVar3;
  size_t _NumOfElements;
  
  _Base = g_arenas[0].cur;
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    pcVar3 = (c1_sym_link *)0x0;
  }
  else {
    pcVar3 = ((cls->x28).members)->head;
  }
  _NumOfElements = 0;
  if (pcVar3 != (c1_sym_link *)0x0) {
    do {
      _NumOfElements = _NumOfElements + 1;
      if (pcVar3 == (c1_sym_link *)0x0) break;
      pcVar3 = pcVar3->next;
    } while (pcVar3 != (c1_sym_link *)0x0);
    if (_NumOfElements != 0) {
      g_arenas[0].cur = g_arenas[0].cur + _NumOfElements * 4;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      piVar2 = (int *)_Base;
      if ((cls->x28).members == (c1_sym_list *)0x0) {
        pcVar3 = (c1_sym_link *)0x0;
      }
      else {
        pcVar3 = ((cls->x28).members)->head;
      }
      for (; pcVar3 != (c1_sym_link *)0x0; pcVar3 = pcVar3->next) {
        *piVar2 = (int)pcVar3;
        if (pcVar3 == (c1_sym_link *)0x0) break;
        piVar2 = piVar2 + 1;
      }
      qsort(_Base,_NumOfElements,4,class_compare_members_by_name);
      pcVar1 = (cls->detail).cls;
      pcVar1->sorted_members = (void **)_Base;
      pcVar1->member_count = _NumOfElements;
    }
  }
  return;
}

