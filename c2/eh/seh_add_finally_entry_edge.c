c2_tuple * __fastcall seh_add_finally_entry_edge(c2_function *fn,c2_tuple *finally_marker)

{
  uint8_t uVar1;
  c2_tuple *anchor;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  
  pcVar3 = finally_marker->next;
  uVar1 = pcVar3->kind;
  while (uVar1 != '\x1a') {
    pcVar3 = pcVar3->next;
    uVar1 = pcVar3->kind;
  }
  tuple_move_before(finally_marker,pcVar3);
  anchor = fn->cfg->first->head;
  uVar2 = anchor->op;
  while (uVar2 != 0x192) {
    anchor = anchor->next;
    uVar2 = anchor->op;
  }
  pcVar3 = tuple_new_branch(0x18b,'\0',(c2_node *)pcVar3,(c2_operand *)0x0,(c2_tuple *)0x0,
                            tuple_insert_after,anchor);
  return pcVar3;
}

