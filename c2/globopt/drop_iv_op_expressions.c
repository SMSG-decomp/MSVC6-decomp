void drop_iv_op_expressions(void)

{
  c2_copy_link *pcVar1;
  c2_copy_link *pcVar2;
  c2_cse_expr **prev_link;
  c2_cse_expr **bucket;
  c2_copy_link *copy_link_0;
  c2_symbol *source_sym;
  c2_symbol *expr_sym;
  c2_copy_link *source_walk;
  c2_copy_link *copy_link;
  c2_cse_expr *entry;
  c2_cse_expr **link;
  
  bucket = g_expr_hash;
  do {
    link = bucket;
    for (entry = *bucket; entry != (c2_cse_expr *)0x0; entry = entry->next) {
      prev_link = &entry->next;
      if ((0x178 < entry->op) && (entry->op < 0x17d)) {
        expr_sym = entry->sym;
        *link = entry->next;
        (expr_sym->u18).expr = (c2_cse_expr *)0x0;
        copy_link = (expr_sym->u38).copy_links;
        while (prev_link = link, copy_link != (c2_copy_link *)0x0) {
          source_sym = copy_link->source;
          pcVar1 = copy_link->next_of_copy;
          (expr_sym->u38).copy_links = pcVar1;
          pcVar2 = (c2_copy_link *)&source_sym->u34;
          for (source_walk = (source_sym->u34).source_links; source_walk != copy_link;
              source_walk = ((c2_symbol_u34 *)&source_walk->next_of_source)->source_links) {
            pcVar2 = source_walk;
          }
          *(c2_copy_link **)&pcVar2->next_of_source = copy_link->next_of_source;
          copy_link = pcVar1;
        }
      }
      link = prev_link;
    }
    bucket = bucket + 1;
  } while ((int)bucket < 0x10799610);
  return;
}

