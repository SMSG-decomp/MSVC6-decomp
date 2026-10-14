void __fastcall
inline_rewrite_returns(c2_function *callee,c2_function *caller,c2_symbol *result,c2_tuple *call)

{
  uint8_t uVar1;
  uint16_t uVar2;
  uint32_t uVar3;
  c2_symbol *sym;
  c2_operand *dst;
  c2_tuple *pcVar4;
  c2_tuple *t;
  int iVar5;
  c2_symbol *pcVar6;
  c2_operand *pcVar7;
  c2_fe_symbol *label_sym;
  ushort uVar8;
  c2_tuple *body_t;
  c2_insert_fn *insert_fn;
  c2_tuple *next_t;
  
  sym = result;
  if ((result != (c2_symbol *)0x0) &&
     ((((uVar1 = result->cls, uVar1 == '\x03' || (uVar1 == '\x04')) || (uVar1 == '\x05')) ||
      (result = (c2_symbol *)0x14b, uVar1 == '\x06')))) {
    result = (c2_symbol *)0x14a;
  }
  body_t = callee->cfg->first->head;
  if (body_t != (c2_tuple *)0x0) {
    uVar2 = call->line;
    do {
      uVar3 = body_t->op;
      next_t = body_t->next;
      body_t->line = uVar2;
      if (uVar3 == 0x16c) {
        if (sym == (c2_symbol *)0x0) {
          for (pcVar7 = body_t->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
            if (((1 << (pcVar7->kind & 0x1f) & 6U) != 0) &&
               (pcVar4 = pcVar7->sym->def, pcVar4 != (c2_tuple *)0x0)) {
              tuple_delete_if_dead((c2_node *)pcVar4,0);
            }
          }
LAB_10751b5f:
          tuple_unlink_free(body_t);
        }
        else {
          pcVar7 = body_t->src;
          if (((1 << (pcVar7->kind & 0x1f) & 6U) == 0) ||
             (pcVar4 = pcVar7->sym->def, pcVar4 == (c2_tuple *)0x0)) {
            insert_fn = tuple_insert_before;
            pcVar4 = body_t;
          }
          else {
            insert_fn = tuple_insert_after;
          }
          dst = operand_new_sym((uint32_t)result,body_t->type,sym);
          pcVar4 = tuple_new(0x15b,body_t->type,dst,pcVar7,insert_fn,pcVar4);
          pcVar4->line = body_t->line;
          tuple_unlink_free(body_t);
        }
      }
      else if (uVar3 == 0x191) {
        if ((sym != (c2_symbol *)0x0) && (iVar5 = inline_body_is_trivial(body_t), iVar5 != 0)) {
          uVar8 = sym->type;
          if ((uVar8 & 0xf000) == 0x3000) {
            uVar8 = 0x1004;
          }
          if (((uVar8 & 0xfff) < 5) || ((uVar8 & 0xf000) == 0x4000)) {
            pcVar7 = operand_new_sym((uint32_t)result,uVar8,sym);
            tuple_append_dst(body_t,pcVar7);
          }
          else {
            uVar8 = uVar8 & 0xf004 | 4;
            pcVar6 = symbol_get_part(sym,uVar8,4,0);
            pcVar7 = operand_new_sym((uint32_t)result,uVar8,pcVar6);
            tuple_append_dst(body_t,pcVar7);
            pcVar6 = symbol_get_part(sym,uVar8,4,4);
            pcVar7 = operand_new_sym((uint32_t)result,uVar8,pcVar6);
            tuple_append_dst(body_t,pcVar7);
          }
        }
      }
      else if (body_t->kind == '\x16') {
        if ((g_opt_global == 0) || ((uVar3 != 0x1b4 && (uVar3 != 0x1b5)))) goto LAB_10751b5f;
        body_t->flags12 = '\x01';
      }
      else if (uVar3 == 0x18c) {
        pcVar4 = caller->cfg->last->end;
        t = tuple_prev_real_in_block(pcVar4);
        if ((t == (c2_tuple *)0x0) || (t->kind != '\x1a')) {
          label_sym = label_symbol_new();
          t = tuple_new_label(label_sym);
          tuple_insert_before(pcVar4->prev,t);
        }
        tuple_retarget(body_t,(c2_node *)t,0);
      }
      body_t = next_t;
    } while (next_t != (c2_tuple *)0x0);
  }
  return;
}

