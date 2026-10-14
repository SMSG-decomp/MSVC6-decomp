void __fastcall tmpl_function_item_run(c1xx_tmpl_function_item *item)

{
  if (item->sym == (c1_symbol *)0x0) {
    diag_fatal(1,".\\template.cpp",0x2d4);
  }
  item->armed = '\0';
  if (0x100 < (uint)item->runs) {
    diag_error(0x3e4,item->sym);
    return;
  }
  tmpl_instantiate_function_definition(item);
  item->runs = item->runs + 1;
  return;
}

