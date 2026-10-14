c2_node * __fastcall reader_address_of_top(c2_reader_cell *cell,uint16_t type)

{
  byte bVar1;
  ushort type_00;
  c2_operand *src;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_const_operand *pcVar4;
  c2_fe_symbol *fs;
  c2_operand *dst;
  c2_insert_fn *insert_fn;
  
  src = reader_pop_operand(cell);
  bVar1 = src->kind;
  do {
    if (bVar1 == 0) {
LAB_107855c5:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0xa81);
    }
    if (2 < bVar1) {
      if (bVar1 == 6) {
        if (src->base != (c2_operand *)0x0) {
          pcVar2 = (c2_tuple *)node_clone((c2_node *)src->base);
          if ((src->flags & 0x10) == 0) {
            node_free((c2_node *)src);
          }
          pcVar3 = cell->tail;
          *(byte *)&pcVar2->line = (byte)pcVar2->line & 0xdf;
          pcVar2->type = type;
          tuple_splice_after(pcVar3,pcVar2);
          cell->tail = pcVar2;
          return (c2_node *)pcVar2;
        }
        pcVar4 = operand_new_intconst(type,src->disp,src->disp >> 0x1f);
        node_free((c2_node *)src);
        tuple_splice_after(cell->tail,(c2_tuple *)pcVar4);
        cell->tail = (c2_tuple *)pcVar4;
        return (c2_node *)pcVar4;
      }
      goto LAB_107855c5;
    }
    dst = src;
    if (((bVar1 != 1) || (src->sym->cls != '\x03')) ||
       (pcVar2 = src->sym->def, pcVar2 == (c2_tuple *)0x0)) {
LAB_10752f82:
      if ((dst->flags & 0x10) != 0) {
        dst = (c2_operand *)node_clone((c2_node *)dst);
      }
      operand_to_address_form(dst);
      pcVar2 = cell->tail;
      dst->type = type;
      tuple_splice_after(pcVar2,(c2_tuple *)dst);
      cell->tail = (c2_tuple *)dst;
      return (c2_node *)dst;
    }
    if ((src->type & 0xf000) == 0x5000) {
      fs = fe_symbol_new_local(g_reading_function->scope,6,g_reader_aggregate_size,1,1,'\x04',0);
      dst = operand_for_fe_symbol(fs);
      type_00 = src->type;
      pcVar2 = cell->tail;
      insert_fn = tuple_splice_after;
      pcVar4 = operand_new_intconst(0x1004,type_00 & 0xfff,0);
      pcVar2 = tuple_new_blockop(0x16b,type_00,dst,src,pcVar4,insert_fn,pcVar2);
      cell->tail = pcVar2;
      goto LAB_10752f82;
    }
    if (pcVar2->op != 0x15b) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0xa5a);
    }
    if (src->type != pcVar2->dst->type) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0xa5b);
    }
    node_free((c2_node *)src);
    pcVar3 = (c2_tuple *)node_clone((c2_node *)pcVar2->src);
    cell->tail = pcVar2->prev;
    tuple_unlink(pcVar2);
    node_free((c2_node *)pcVar2);
    tuple_splice_after(cell->tail,pcVar3);
    cell->tail = pcVar3;
    src = reader_pop_operand(cell);
    bVar1 = src->kind;
  } while( true );
}

