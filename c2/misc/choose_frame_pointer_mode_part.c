void __fastcall
choose_frame_pointer_mode_part
          (int list_pass,int loop_weight,c2_operand *opnd,c2_tuple *tuple,int double_score,
          c2_block *block,int esp_double_score,int has_aligned_local,c2_function *fn,
          c2_tuple *block_end,uint32_t fn_flags)

{
  uint uVar1;
  uint8_t uVar2;
  c2_fe_symbol *pcVar3;
  int iVar4;
  int iVar5;
  c2_tuple *pcVar6;
  c2_symbol *pcVar7;
  c2_block *pcVar8;
  
code_r0x10720574:
  double_score = double_score + loop_weight;
LAB_107205bb:
  do {
    opnd = opnd->next;
    pcVar8 = block;
    pcVar6 = block_end;
    while (block = pcVar8, block_end = pcVar6, opnd == (c2_operand *)0x0) {
      list_pass = list_pass + 1;
      if (1 < list_pass) {
        do {
          tuple = tuple->next;
          if (tuple == pcVar6) {
            do {
              iVar5 = g_frame_has_param_double_refs;
              pcVar8 = pcVar8->next;
              if (pcVar8 == (c2_block *)0x0) {
                uVar1 = double_score + esp_double_score * 3;
                if ((uVar1 < 0xfa) && ((g_frame_has_param_double_refs != 0 || (uVar1 < 0x10)))) {
                  if (0xe < uVar1) {
                    g_aligned_frame_score = uVar1;
                    return;
                  }
                }
                else {
                  iVar4._0_1_ = g_cur_func_sym->level;
                  iVar4._1_1_ = g_cur_func_sym->combine;
                  iVar4._2_2_ = g_cur_func_sym->u44;
                  fn->flags = fn_flags | 0x600000;
                  if ((iVar4 != 0) && (iVar5 != 0)) {
                    fn->flags = CONCAT31((int3)((fn_flags | 0x600000) >> 8),(char)fn_flags) &
                                0xffffffef;
                  }
                }
                return;
              }
              loop_weight = int_power(10,(int)pcVar8->loop_depth);
              tuple = pcVar8->head->next;
              pcVar6 = pcVar8->end;
              block = pcVar8;
              block_end = pcVar6;
            } while (tuple == pcVar6);
          }
        } while ((tuple->flags & 1) == 0);
        list_pass = 0;
      }
      pcVar8 = block;
      pcVar6 = block_end;
      if (list_pass == 0) {
        opnd = tuple->src;
      }
      else {
        opnd = tuple->dst;
      }
    }
    switch(opnd->kind) {
    case '\x02':
    case '\x03':
      pcVar7 = opnd->sym;
      break;
    default:
      goto switchD_107204cc_caseD_4;
    case '\x05':
    case '\x06':
      pcVar7 = opnd->base_sym;
    }
    if (pcVar7 == (c2_symbol *)0x0) goto switchD_107204cc_caseD_4;
    pcVar7 = pcVar7->storage;
    uVar2 = pcVar7->cls;
    if (uVar2 == '\x05') {
      g_frame_has_param_double_refs = 1;
      goto switchD_107204cc_caseD_4;
    }
  } while ((uVar2 == '\a') || (uVar2 == '\b'));
  if (uVar2 == '\x04') {
    if (pcVar7->type == 0x4008) goto code_r0x10720574;
    pcVar3 = pcVar7->fe;
    if ((((pcVar3 != (c2_fe_symbol *)0x0) && (pcVar3->cls == '\x01')) &&
        ((pcVar3->storage & 0x10000) != 0)) && (*(int *)((int)&pcVar3->u3e + 2) == 8)) {
      choose_frame_pointer_mode_part
                (list_pass,loop_weight,opnd,tuple,double_score,pcVar8,esp_double_score,
                 has_aligned_local,fn,pcVar6,fn_flags);
      return;
    }
  }
switchD_107204cc_caseD_4:
  if ((opnd->type == 0x4008) && (opnd->kind == '\x06')) {
    if ((opnd->op == 0x14c) &&
       ((opnd->base->kind == '\x01' && ((opnd->base->u18).reg == g_reg_symbols + 5)))) {
      esp_double_score = esp_double_score + loop_weight;
    }
    else if (has_aligned_local != 0) {
      choose_frame_pointer_mode_part
                (list_pass,loop_weight,opnd,tuple,double_score,pcVar8,esp_double_score,
                 has_aligned_local,fn,pcVar6,fn_flags);
      return;
    }
  }
  goto LAB_107205bb;
}

