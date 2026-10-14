c1_node * __thiscall
expr_prepare_member_access_object(c1_scope_stack *scope,char op,c1_node *object,char no_arrow)

{
  c1_symbol *cls;
  char cVar1;
  c1_type *pcVar2;
  c1_node *left;
  byte *token;
  byte *token_00;
  byte *token_01;
  byte *token_02;
  c1_node *pcVar3;
  
  left = object;
  if ((object != (c1_node *)0x0) && (object->op == 0xe8)) {
    left = property_build_access('\x01',object,(c1_node *)0x0);
  }
  cVar1 = op;
  scope->qualified = '\x01';
  scope->access_op = op;
  scope->reported = '\0';
  if (left == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar2 = left->type;
  if ((op == 'S') && ((char)pcVar2->code < '\0')) {
    pcVar2 = pcVar2->base;
  }
  if (((pcVar2->code & 0x200) != 0) && (cls = (pcVar2->extra).cls, cls != (c1_symbol *)0x0)) {
    if (((cls->flags2 & 4) == 0) && (tmpl_instantiate_if_needed(cls), (cls->flags2 & 4) == 0)) {
      if (g_opt_Zg == '\0') {
        diag_error(0x1b,cls);
      }
      return (c1_node *)0x0;
    }
    if (((no_arrow == '\0') && (cVar1 == 'S')) && ((left->type->code & 0x200) != 0)) {
      op = '\0';
      pcVar3 = expr_apply_overloaded_operator('S',left,(c1_node *)0x0,1,1,(byte *)&op);
      if (pcVar3 != (c1_node *)0x0) {
        if (op != '\0') {
          return pcVar3;
        }
        pcVar3 = expr_prepare_member_access_object(scope,'S',pcVar3,'\0');
        if (pcVar3 != (c1_node *)0x0) {
          return pcVar3;
        }
      }
    }
    scope->qual_class = cls;
    return left;
  }
  if (((op == 'S') || (op == 'P')) &&
     (token = token_next((c1_token_reader *)&g_token_position), token != (byte *)0x0)) {
    if ((*token == 6) &&
       (token_00 = token_next((c1_token_reader *)&g_token_position), token_00 != (byte *)0x0)) {
      if ((*token_00 == 0x95) &&
         (token_01 = token_next((c1_token_reader *)&g_token_position), token_01 != (byte *)0x0)) {
        if ((*token_01 == 0x59) &&
           (token_02 = token_next((c1_token_reader *)&g_token_position), token_02 != (byte *)0x0)) {
          if (*token_02 == 6) {
            scope->qualified = '\0';
            scope->access_op = '\x01';
          }
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token_02);
        }
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token_01);
      }
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token_00);
    }
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
  }
  return (c1_node *)0x0;
}

