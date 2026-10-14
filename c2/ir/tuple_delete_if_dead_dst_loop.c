c2_node * tuple_delete_if_dead_dst_loop(c2_tuple *t,c2_operand *opnd,int keep_side_effects)

{
  ushort type;
  int iVar1;
  c2_node *pcVar2;
  c2_const_operand *size;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  c2_insert_fn *insert_fn;
  
  while (pcVar6 = opnd, pcVar6 != (c2_operand *)0x0) {
    opnd = pcVar6->next;
    if (((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (pcVar6->sym->def != (c2_tuple *)0x0)) {
      if (pcVar6->kind == 1) {
        tuple_drop_dead_dst(t,pcVar6);
      }
      else if ((t->op == 0x16a) || (t->op == 0x16b)) {
        tuple_remove_dst(t,pcVar6);
        pcVar2 = tuple_delete_if_dead_dst_loop(t,opnd,keep_side_effects);
        return pcVar2;
      }
    }
  }
  pcVar6 = t->dst;
  do {
    if (pcVar6 == (c2_operand *)0x0) {
      if ((keep_side_effects == 0) && (iVar1 = node_has_side_effects((c2_node *)t), iVar1 != 0)) {
        switch(t->kind) {
        case '\f':
          if (t->dst == (c2_operand *)0x0) {
            pcVar5 = t;
            for (pcVar6 = t->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
              if ((pcVar6->flags & 0x20) == 0) {
                type = pcVar6->type;
                insert_fn = tuple_splice_after;
                if ((pcVar6->type & 0xf000) == 0x5000) {
                  size = operand_new_intconst(type,type & 0xfff,0);
                  pcVar3 = (c2_operand *)node_clone((c2_node *)pcVar6);
                  pcVar4 = operand_new_temp_sym(type);
                  pcVar5 = tuple_new_blockop(0x16b,type,pcVar4,pcVar3,size,insert_fn,pcVar5);
                }
                else {
                  pcVar3 = (c2_operand *)node_clone((c2_node *)pcVar6);
                  pcVar4 = operand_new_temp_sym(type);
                  pcVar5 = tuple_new(0x15b,type,pcVar4,pcVar3,insert_fn,pcVar5);
                }
              }
            }
            tuple_unlink(t);
            node_free((c2_node *)t);
            return (c2_node *)pcVar5;
          }
          break;
        default:
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\sdsu.c",0x1bb);
        case '\x0e':
        case '\x0f':
        case '\x11':
        case '\x12':
        case '\x14':
        case '\x15':
          break;
        }
      }
      else {
        for (pcVar6 = t->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
          if (((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (pcVar6->sym->def != (c2_tuple *)0x0)) {
            tuple_drop_unused_results(pcVar6);
          }
        }
        pcVar5 = t->prev;
        tuple_unlink(t);
        node_free((c2_node *)t);
        t = pcVar5;
      }
      return (c2_node *)t;
    }
    if (pcVar6->kind != '\x01') {
      return (c2_node *)t;
    }
    if (((pcVar6->u18).reg)->cls != '\x01') {
      return (c2_node *)t;
    }
    pcVar6 = pcVar6->next;
  } while( true );
}

