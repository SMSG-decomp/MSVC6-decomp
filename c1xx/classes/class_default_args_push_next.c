char __fastcall class_default_args_push_next(c1_deferred_parse *rec)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  
  if (rec->parse_pending != '\0') {
    default_argument_store_and_advance(rec,(c1_node *)0x0);
  }
  pcVar1 = rec->default_arg;
  if (pcVar1 != (c1_node *)0x0) {
    pcVar2 = pcVar1->left;
    rec->saved_tokens = pcVar2;
    if (pcVar2->op != 0xc6) {
      do {
        rec->default_arg = pcVar1->link;
        rec->param_type = rec->param_type + 1;
        pcVar1 = rec->default_arg;
        if (pcVar1 == rec->last_default) {
          return '\0';
        }
        pcVar2 = pcVar1->left;
        rec->saved_tokens = pcVar2;
      } while (pcVar2->op != 0xc6);
    }
    token_source_push((c1_token_reader *)&g_token_position,pcVar2->left,10,1,
                      class_default_args_on_tokens_end,&g_token_position);
    rec->parse_pending = '\x01';
    return '\x01';
  }
  return '\0';
}

