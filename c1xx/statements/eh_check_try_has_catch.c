void eh_check_try_has_catch(void)

{
  c1_try_block *try_block;
  
  if ((((PTR_104d2cb8 != (c1_vector *)0x0) && (PTR_104d2cb8->count != 0)) &&
      (try_block = PTR_104d2cb8->data[PTR_104d2cb8->count - 1], try_block != (c1_try_block *)0x0))
     && (try_block->handlers != (c1_vector *)0x0)) {
    if (try_block->handlers->count == 0) {
      diag_error(0x13d,try_block->line);
    }
    il_emit_eh_trymap();
    label_emit_definition(try_block->end_label);
    if (PTR_104d2cbc == (c1_vector *)0x0) {
      PTR_104d2cbc = vector_new(0,4);
    }
    vector_push(PTR_104d2cbc,PTR_104d2cb8->data[PTR_104d2cb8->count - 1]);
    PTR_104d2cb8->count = PTR_104d2cb8->count - 1;
  }
  return;
}

