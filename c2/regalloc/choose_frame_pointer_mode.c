void __fastcall choose_frame_pointer_mode(c2_function *fn)

{
  uint8_t uVar1;
  uint uVar2;
  c2_tuple *tuple;
  c2_tuple *block_end;
  c2_fe_symbol *pcVar3;
  c2_operand *opnd;
  uint fn_flags;
  int loop_weight;
  c2_symbol *sym;
  c2_function *pcVar4;
  int list_pass;
  c2_block *pcVar5;
  bool bVar6;
  int iVar7;
  c2_block *block;
  int has_aligned_local;
  int param_double_score;
  c2_symbol_chunk *chunk;
  
  param_double_score = g_double_align_bias;
  uVar2 = fn->flags;
  bVar6 = g_opt_omit_frame_pointer != 0;
  iVar7 = 0;
  g_aligned_frame_score = 0;
  g_frame_has_param_double_refs = 0;
  fn->flags = uVar2 & 0xff9fffef;
  if ((((bVar6) && ((uVar2 & 0xc1) == 0)) && ((fn->fsym->attrs & 0x1000) == 0)) &&
     ((uVar2 & 0x10000) == 0)) {
    fn_flags = uVar2 & 0xff9fffef | 0x10;
    bVar6 = g_opt_global != 0;
    fn->flags = fn_flags;
    if (((bVar6) && (g_opt_favor_speed != 0)) && (((uVar2 & 1) == 0 && ((uVar2 & 8) != 0)))) {
      has_aligned_local = 0;
      for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
        for (sym = chunk->syms; sym < chunk->cursor; sym = sym + 1) {
          if (((sym->cls != '\x10') && (sym->cls == '\x04')) && ((sym->flags5 & 2) != 0)) {
            has_aligned_local = 1;
            break;
          }
        }
      }
      loop_weight = 0;
      pcVar4 = fn;
      for (pcVar5 = fn->cfg->first; pcVar5 != (c2_block *)0x0; pcVar5 = pcVar5->next) {
        block = pcVar5;
        loop_weight = int_power(10,(int)pcVar5->loop_depth);
        block_end = pcVar5->end;
        for (tuple = pcVar5->head->next; tuple != block_end; tuple = tuple->next) {
          if ((tuple->flags & 1) != 0) {
            list_pass = 0;
            do {
              if (list_pass == 0) {
                opnd = tuple->src;
              }
              else {
                opnd = tuple->dst;
              }
              for (; opnd != (c2_operand *)0x0; opnd = opnd->next) {
                switch(opnd->kind) {
                case '\x02':
                case '\x03':
                  sym = opnd->sym;
                  break;
                default:
                  goto switchD_107204cc_caseD_4;
                case '\x05':
                case '\x06':
                  sym = opnd->base_sym;
                }
                if (sym == (c2_symbol *)0x0) {
switchD_107204cc_caseD_4:
                  if ((opnd->type == 0x4008) && (opnd->kind == '\x06')) {
                    if ((opnd->op == 0x14c) &&
                       ((opnd->base->kind == '\x01' && ((opnd->base->u18).reg == g_reg_symbols + 5))
                       )) {
                      param_double_score = param_double_score + loop_weight;
                    }
                    else if (has_aligned_local != 0) {
                      choose_frame_pointer_mode_part
                                (list_pass,loop_weight,opnd,tuple,iVar7,block,param_double_score,
                                 has_aligned_local,fn,block_end,fn_flags);
                      return;
                    }
                  }
                }
                else {
                  sym = sym->storage;
                  uVar1 = sym->cls;
                  if (uVar1 == '\x05') {
                    g_frame_has_param_double_refs = 1;
                    goto switchD_107204cc_caseD_4;
                  }
                  if ((uVar1 != '\a') && (uVar1 != '\b')) {
                    if (uVar1 == '\x04') {
                      if (sym->type == 0x4008) {
                        iVar7 = iVar7 + loop_weight;
                        goto LAB_107205bb;
                      }
                      pcVar3 = sym->fe;
                      if ((((pcVar3 != (c2_fe_symbol *)0x0) && (pcVar3->cls == '\x01')) &&
                          ((pcVar3->storage & 0x10000) != 0)) &&
                         (*(int *)((int)&pcVar3->u3e + 2) == 8)) {
                        choose_frame_pointer_mode_part
                                  (list_pass,loop_weight,opnd,tuple,iVar7,block,param_double_score,
                                   has_aligned_local,fn,block_end,fn_flags);
                        return;
                      }
                    }
                    goto switchD_107204cc_caseD_4;
                  }
                }
LAB_107205bb:
              }
              list_pass = list_pass + 1;
              pcVar4 = fn;
              pcVar5 = block;
            } while (list_pass < 2);
          }
        }
        loop_weight = g_frame_has_param_double_refs;
      }
      uVar2 = iVar7 + param_double_score * 3;
      if ((uVar2 < 0xfa) && ((loop_weight != 0 || (uVar2 < 0x10)))) {
        if (0xe < uVar2) {
          g_aligned_frame_score = uVar2;
          return;
        }
      }
      else {
        iVar7._0_1_ = g_cur_func_sym->level;
        iVar7._1_1_ = g_cur_func_sym->combine;
        iVar7._2_2_ = g_cur_func_sym->u44;
        pcVar4->flags = fn_flags | 0x600000;
        if ((iVar7 != 0) && (loop_weight != 0)) {
          pcVar4->flags = CONCAT31((int3)((fn_flags | 0x600000) >> 8),(char)fn_flags) & 0xffffffef;
        }
      }
    }
  }
  return;
}

