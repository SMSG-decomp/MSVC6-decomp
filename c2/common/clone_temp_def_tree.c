c2_operand * __fastcall clone_temp_def_tree(c2_symbol *sym,c2_tuple **first,c2_tuple **last)

{
  ushort uVar1;
  c2_tuple *t;
  c2_operand *new_op;
  c2_symbol *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *local_8;
  c2_tuple *local_4;
  
  t = (c2_tuple *)node_clone((c2_node *)sym->def);
  *first = t;
  pcVar3 = t->src;
  *last = t;
  while (pcVar4 = pcVar3, pcVar4 != (c2_operand *)0x0) {
    pcVar3 = pcVar4->next;
    if (((1 << (pcVar4->kind & 0x1f) & 6U) != 0) && (pcVar4->sym->def != (c2_tuple *)0x0)) {
      new_op = clone_temp_def_tree(pcVar4->sym,&local_4,&local_8);
      uVar1 = pcVar4->type;
      if (uVar1 != new_op->type) {
        new_op->type = uVar1;
        pcVar2 = symbol_get_part(new_op->sym,uVar1,uVar1 & 0xfff,0);
        new_op->sym = pcVar2;
      }
      tuple_replace_src(t,pcVar4,new_op);
      tuple_splice_after(local_8,*first);
      *first = local_4;
    }
  }
  pcVar3 = t->dst;
  pcVar4 = (c2_operand *)0x0;
  if (pcVar3 != (c2_operand *)0x0) {
    do {
      if (((1 << (pcVar3->kind & 0x1f) & 6U) != 0) &&
         (pcVar2 = pcVar3->sym, pcVar2->def != (c2_tuple *)0x0)) {
        operand_set_fresh_temp(pcVar3);
        pcVar2 = pcVar2->storage;
        pcVar3->sym->def = t;
        if (pcVar2 == sym->storage) {
          pcVar4 = (c2_operand *)node_clone((c2_node *)pcVar3);
          uVar1 = sym->type;
          if (pcVar4->type != uVar1) {
            pcVar4->type = uVar1;
            pcVar2 = symbol_get_part(pcVar4->sym,uVar1,uVar1 & 0xfff,0);
            pcVar4->sym = pcVar2;
          }
        }
      }
      pcVar3 = pcVar3->next;
    } while (pcVar3 != (c2_operand *)0x0);
    if (pcVar4 != (c2_operand *)0x0) {
      return pcVar4;
    }
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\sdsu.c",0xa5);
}

