c2_tuple * __fastcall lower_block_copy(c2_tuple *t)

{
  byte bVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_const_operand *pcVar5;
  c2_node *a;
  c2_node *b;
  c2_tuple *pcVar6;
  uint32_t uVar7;
  uint32_t alias2;
  uint32_t local_4;
  c2_insert_fn *insert_fn;
  
  if (t->op != 0x16b) {
    uVar7 = arg_stack_size((c2_node *)t);
    pcVar5 = operand_new_intconst(0x1004,uVar7,(int)uVar7 >> 0x1f);
    emit_alloca_stack_adjust(pcVar5,tuple_insert_before,t);
    if (t->op == 0x16a) {
      pcVar5 = operand_new_intconst(0x1004,t->type & 0xfff,0);
      uVar7 = 0;
      if (g_opt_global == 0) {
        local_4 = 0;
      }
      else {
        pcVar3 = t->src;
        local_4 = 2;
        if (pcVar3->kind == '\x06') {
          uVar7 = pcVar3->tag;
        }
        else {
          uVar7 = (uint32_t)(pcVar3->sym->storage->fe->u3e).alias_class;
        }
      }
      pcVar3 = (c2_operand *)block_operand_address((int)t,t->src,0x10702130);
    }
    else {
      pcVar6 = t->src->sym->def;
      tuple_replace_src(t,t->src,pcVar6->src);
      tuple_unlink_free(pcVar6);
      pcVar3 = t->src;
      if (g_opt_global == 0) {
        local_4 = 0;
        uVar7 = 0;
      }
      else {
        bVar1 = pcVar3->kind;
        uVar7 = 2;
        local_4 = 2;
        if (bVar1 == 6) {
          uVar7 = pcVar3->tag;
        }
        else if (bVar1 != 7) {
          if (((1 << (bVar1 & 0x1f) & 6U) == 0) ||
             (pcVar6 = pcVar3->sym->def, pcVar6 == (c2_tuple *)0x0)) {
            uVar7 = (uint32_t)(pcVar3->sym->storage->fe->u3e).alias_class;
          }
          else {
            if (pcVar6->op != 0x12) {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\cgintrin.c",0x7a2);
            }
            uVar7 = (uint32_t)(pcVar6->src->sym->storage->fe->u3e).alias_class;
          }
        }
      }
      pcVar6 = pcVar3->next->sym->def;
      tuple_replace_src(t,pcVar3->next,pcVar6->src);
      tuple_unlink_free(pcVar6);
      pcVar5 = t->src->next;
    }
    insert_fn = tuple_insert_after;
    pcVar4 = operand_new_hardreg(5,0x1004);
    pcVar6 = (c2_tuple *)
             build_block_copy_intrinsic
                       ((c2_operand *)0x0,(c2_node *)pcVar4,(c2_node *)pcVar3,pcVar5,t,local_4,uVar7
                        ,insert_fn);
    return pcVar6;
  }
  uVar7 = 0;
  pcVar3 = t->dst;
  if ((((1 << (pcVar3->kind & 0x1f) & 6U) != 0) && (pcVar3->sym->def != (c2_tuple *)0x0)) &&
     ((pcVar3->type & 0xf000) == 0x5000)) {
    return t;
  }
  pcVar3 = t->src;
  if ((((1 << (pcVar3->kind & 0x1f) & 6U) != 0) &&
      (pcVar6 = pcVar3->sym->def, pcVar6 != (c2_tuple *)0x0)) &&
     (((pcVar3->type & 0xf000) == 0x5000 && (pcVar6->op == 0x16b)))) {
    tuple_replace_src(t,pcVar3,pcVar6->src);
    tuple_unlink_free(pcVar6);
  }
  pcVar3 = t->dst;
  pcVar4 = pcVar3->next;
  if (pcVar4 == (c2_operand *)0x0) {
    pcVar4 = pcVar3;
    pcVar3 = (c2_operand *)0x0;
  }
  pcVar5 = operand_new_intconst(0x1004,t->type & 0xfff,0);
  if (g_opt_global == 0) {
    alias2 = 0;
  }
  else {
    if (pcVar4->kind == '\x06') {
      uVar7 = pcVar4->tag;
    }
    else {
      uVar7 = (uint32_t)(pcVar4->sym->storage->fe->u3e).alias_class;
    }
    pcVar2 = t->src;
    if (pcVar2->kind == '\x06') {
      alias2 = pcVar2->tag;
    }
    else {
      alias2 = (uint32_t)(pcVar2->sym->storage->fe->u3e).alias_class;
    }
  }
  a = block_operand_address((int)t,pcVar4,0x10702c7b);
  b = block_operand_address((int)t,t->src,0x10702130);
  pcVar6 = (c2_tuple *)
           build_block_copy_intrinsic(pcVar3,a,b,pcVar5,t,uVar7,alias2,tuple_insert_before);
  tuple_unlink_free(t);
  return pcVar6;
}

