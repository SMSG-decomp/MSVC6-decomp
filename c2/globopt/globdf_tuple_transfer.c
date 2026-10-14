void __fastcall globdf_tuple_transfer(c2_tuple *t)

{
  uint8_t uVar1;
  byte bVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  int iVar5;
  uint32_t uVar6;
  c2_bitset *src;
  c2_bitset *src_00;
  c2_fe_symbol *pcVar7;
  c2_symbol *pcVar8;
  
  if (((((g_liveness_mode == 0) || (t->flags13 != '\x04')) && (uVar1 = t->flags13, uVar1 != '\x02'))
      && (uVar1 != '\x01')) && ((uVar1 != '\x11' || (g_need_extra_dce != 0)))) {
    for (pcVar3 = t->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
      bVar2 = pcVar3->kind;
      if (((bVar2 != 0) && (bVar2 < 3)) &&
         (((1 << (bVar2 & 0x1f) & 6U) == 0 || (pcVar3->sym->def == (c2_tuple *)0x0)))) {
        pcVar4 = pcVar3->sym;
        pcVar8 = pcVar4->storage;
        if (pcVar8 != (c2_symbol *)0x0) {
          iVar5 = pcVar4->offset;
          do {
            if ((iVar5 <= pcVar8->offset) && (pcVar8->size + pcVar8->offset <= pcVar4->size + iVar5)
               ) {
              uVar6 = pcVar8->id;
              bitset_set(g_df_block_def,uVar6);
              bitset_clear(g_df_block_use,uVar6);
              bitset_set(g_df_block_part_def,uVar6);
              bitset_clear(g_df_block_part_use,uVar6);
            }
            pcVar8 = pcVar8->part_next;
          } while (pcVar8 != (c2_symbol *)0x0);
        }
        if (((pcVar4->u18).expr != (c2_cse_expr *)0x0) && (((pcVar4->u18).expr)->op == 0x14c)) {
          globdf_mark_copy_parts(pcVar4);
        }
      }
    }
    for (pcVar3 = t->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
      switch(pcVar3->kind) {
      case '\0':
        halt_baddata();
      case '\x01':
      case '\x02':
        if (((1 << (pcVar3->kind & 0x1f) & 6U) == 0) || (pcVar3->sym->def == (c2_tuple *)0x0)) {
          pcVar4 = pcVar3->sym;
          uVar6 = pcVar4->id;
          bitset_set(g_df_block_use,uVar6);
          bitset_clear(g_df_block_def,uVar6);
          for (pcVar8 = pcVar4->storage; pcVar8 != (c2_symbol *)0x0; pcVar8 = pcVar8->part_next) {
            if (pcVar8 == pcVar4) {
LAB_1070601a:
              uVar6 = pcVar8->id;
              bitset_clear(g_df_block_part_def,uVar6);
              bitset_set(g_df_block_part_use,uVar6);
            }
            else if ((pcVar8->offset < pcVar4->size + pcVar4->offset) &&
                    (pcVar4->offset < pcVar8->size + pcVar8->offset)) goto LAB_1070601a;
          }
        }
        break;
      case '\x03':
        if (t->op == 0x15a) {
          pcVar4 = pcVar3->sym;
          pcVar7 = pcVar4->storage->fe;
          if ((((pcVar7 != (c2_fe_symbol *)0x0) && (pcVar7->cls == '\x01')) &&
              (((byte)pcVar7->storage & 0x70) == 0x10)) &&
             ((pcVar7->name == (char *)0x0 && ((pcVar7->storage & 0x40000) != 0)))) {
            pcVar8 = pcVar4->storage;
            if (pcVar8 != (c2_symbol *)0x0) {
              iVar5 = pcVar4->offset;
              do {
                if ((iVar5 <= pcVar8->offset) &&
                   (pcVar8->size + pcVar8->offset <= pcVar4->size + iVar5)) {
                  uVar6 = pcVar8->id;
                  bitset_set(g_df_block_def,uVar6);
                  bitset_clear(g_df_block_use,uVar6);
                  bitset_set(g_df_block_part_def,uVar6);
                  bitset_clear(g_df_block_part_use,uVar6);
                }
                pcVar8 = pcVar8->part_next;
              } while (pcVar8 != (c2_symbol *)0x0);
            }
            if (((pcVar4->u18).expr != (c2_cse_expr *)0x0) && (((pcVar4->u18).expr)->op == 0x14c)) {
              globdf_mark_copy_parts(pcVar4);
            }
          }
        }
        break;
      case '\x06':
        src = g_alias_class_head_sets[pcVar3->tag];
        src_00 = g_alias_class_member_sets[pcVar3->tag];
        bitset_or(g_df_block_use,src);
        bitset_andnot(g_df_block_def,src);
        bitset_or(g_df_block_part_use,src_00);
        bitset_andnot(g_df_block_part_def,src_00);
      }
    }
  }
  return;
}

