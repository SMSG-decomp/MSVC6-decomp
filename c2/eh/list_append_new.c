c2_eh_object_cell * __fastcall list_append_new(c2_eh_object_cell *list,c2_eh_state *object)

{
  c2_eh_object_cell *pcVar1;
  c2_eh_object_cell *pcVar2;
  c2_eh_object_cell *pcVar3;
  c2_eh_object_cell *pcVar4;
  
  pcVar4 = arena_alloc(1,0xc);
  pcVar4->object = object;
  if (list != (c2_eh_object_cell *)0x0) {
    pcVar3 = list->next;
    pcVar2 = list;
    while (pcVar1 = pcVar3, pcVar1 != (c2_eh_object_cell *)0x0) {
      pcVar2 = pcVar1;
      pcVar3 = pcVar1->next;
    }
    pcVar2->next = pcVar4;
    pcVar4->prev = pcVar2;
    pcVar4 = list;
  }
  return pcVar4;
}

