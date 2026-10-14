void __fastcall narrow_byte_lane_tuple(c2_tuple *t)

{
  c2_tuple *t_00;
  c2_tuple *pcVar1;
  int iVar2;
  c2_operand *pcVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  uint16_t uVar8;
  uint32_t local_18;
  c2_operand *local_14;
  c2_operand *local_10;
  c2_operand *local_c;
  c2_operand *local_8;
  int local_4;
  
  if (((((t->flags & 1) != 0) && ((1 << (t->kind & 0x1f) & 0x2000U) == 0)) &&
      ((t->type & 0xf000) != 0x4000)) && ((t->kind == 0x11 || ((t->type & 0xfff) < 5)))) {
    pcVar6 = t->src;
    while ((pcVar6 != (c2_operand *)0x0 && ((pcVar6->type & 0xfff) < 5))) {
      local_8 = pcVar6->next;
      if ((pcVar6->kind == '\x01') &&
         ((pcVar6->sym->cls == '\x03' && (t_00 = pcVar6->sym->def, t_00 != (c2_tuple *)0x0)))) {
        pcVar3 = t_00->src;
        switch(t_00->op) {
        case 0x16d:
        case 0x173:
          if ((((1 << (pcVar3->kind & 0x1f) & 6U) != 0) && (pcVar3->sym->def != (c2_tuple *)0x0)) &&
             ((pcVar7 = pcVar3->next, (1 << (pcVar7->kind & 0x1f) & 6U) != 0 &&
              (((pcVar7->sym->def != (c2_tuple *)0x0 &&
                (local_18 = classify_byte_lane_source(pcVar7,0,0), (char)(local_18 >> 8) != '\0'))
               && (uVar4 = classify_byte_lane_source(pcVar3,0,0),
                  (int)(uVar4 << 0x10) >> 0x18 == -((int)(local_18 << 0x10) >> 0x18))))))) {
            local_14 = pcVar3->next;
            for (pcVar1 = pcVar3->sym->def; pcVar1 != local_14->sym->def; pcVar1 = pcVar1->next) {
              if (pcVar1 == t_00) goto LAB_10775737;
            }
            uVar5 = uVar4;
            pcVar7 = pcVar3;
            if (pcVar1 == t_00) {
LAB_10775737:
              uVar5 = local_18;
              pcVar7 = local_14;
              local_18 = uVar4;
              local_14 = pcVar3;
              local_10 = pcVar3;
            }
            uVar8 = t_00->type;
            pcVar3 = make_byte_lane_operand(pcVar7,(c2_operand *)0x0,uVar8,1,(char)uVar5);
            pcVar3 = make_byte_lane_operand(local_14,pcVar3,uVar8,1,(char)local_18);
            tuple_unlink_free(t_00);
            try_substitute_operand(t,pcVar6,pcVar3,tuple_replace_src);
          }
          break;
        case 0x171:
        case 0x177:
          uVar4 = classify_byte_lane_source(pcVar6,0,1);
          if (((t_00->op != 0x171) ||
              (find_next_use_of_dst(t_00,&local_c), (local_c->type & 0xfff) != 1)) &&
             ((uVar4 & 0xff00) != 0)) {
            uVar8 = t_00->type;
LAB_10718e21:
            pcVar3 = make_byte_lane_operand(pcVar6,(c2_operand *)0x0,uVar8,1,'\0');
            try_substitute_operand(t,pcVar6,pcVar3,tuple_replace_src);
          }
          break;
        case 0x172:
          uVar4 = classify_byte_lane_source(pcVar6,1,0);
          if ((((uVar4 & 0xff00) != 0) && ((1 << (pcVar3->kind & 0x1f) & 6U) != 0)) &&
             ((pcVar1 = pcVar3->sym->def, pcVar1 != (c2_tuple *)0x0 &&
              (((((uVar4 & 0xff00) == 0x100 && (t_00->src->sym->def->op == 0x171)) &&
                (iVar2 = operand_is_const_value(pcVar1->src->next,8), iVar2 != 0)) ||
               (iVar2 = classify_masked_shift_source(pcVar6,&local_4,(c2_tuple **)&local_10),
               iVar2 != 0)))))) {
            uVar8 = t_00->type;
            goto LAB_10718e21;
          }
          break;
        case 0x17d:
          if (((((1 << (pcVar3->kind & 0x1f) & 6U) != 0) && (pcVar3->sym->def != (c2_tuple *)0x0))
              && ((1 << (pcVar3->next->kind & 0x1f) & 6U) != 0)) &&
             ((pcVar3->next->sym->def != (c2_tuple *)0x0 && (8 < (t_00->type & 0xfff))))) {
            uVar4 = classify_byte_lane_source(pcVar3,0,0);
            uVar5 = classify_byte_lane_source(pcVar3->next,0,0);
            if (((uVar4 & 0xff00) != 0) && ((char)(uVar5 >> 8) != '\0')) {
              pcVar6 = make_byte_lane_operand(pcVar3,(c2_operand *)0x0,0x1001,1,(char)uVar4);
              pcVar7 = make_byte_lane_operand(pcVar3->next,(c2_operand *)0x0,0x1001,0,(char)uVar5);
              tuple_replace_src(t_00,pcVar3,pcVar6);
              tuple_replace_src(t_00,t_00->src->next,pcVar7);
              t_00->type = 0x2001;
            }
          }
        }
      }
      pcVar6 = local_8;
    }
  }
  return;
}

