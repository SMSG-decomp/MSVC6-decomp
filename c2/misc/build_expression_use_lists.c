void build_expression_use_lists(void)

{
  c2_cse_expr **bucket;
  c2_cse_expr *entry;
  
  bucket = g_expr_hash;
  do {
    for (entry = *bucket; entry != (c2_cse_expr *)0x0; entry = entry->next) {
      link_expression_operands(entry->sym);
    }
    bucket = bucket + 1;
  } while ((int)bucket < 0x10799610);
  return;
}

