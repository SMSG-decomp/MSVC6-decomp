void __thiscall
ovl_resolution_init(c1_ovl_resolution *res,c1_symbol *set,c1_u32 nargs,byte op,byte flags)

{
  res->set = set;
  res->specializations = (c1_symbol_vector *)0x0;
  res->count = 0;
  res->nargs = nargs;
  res->tail = (c1_ovl_candidate *)0x0;
  res->ncandidates = 0;
  res->nconversions = 0;
  res->failed = '\0';
  res->flags = flags;
  res->failure = 10;
  res->op = op;
  return;
}

