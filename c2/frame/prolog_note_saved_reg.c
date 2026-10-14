void __fastcall
prolog_note_saved_reg(c2_callee_save_site **list,int regno,c2_block *block,c2_edge *edge,char *what)

{
  c2_callee_save_site *pcVar1;
  c2_callee_save_site *pcVar2;
  
  pcVar1 = *list;
  pcVar2 = pcVar1;
  if (edge == (c2_edge *)0x0) {
    for (; (pcVar2 != (c2_callee_save_site *)0x0 && (pcVar2->block != block)); pcVar2 = pcVar2->next
        ) {
    }
  }
  pcVar2 = arena_alloc(4,0xc);
  *list = pcVar2;
  pcVar2->next = pcVar1;
  pcVar2->edge = edge;
  pcVar2->block = block;
  return;
}

