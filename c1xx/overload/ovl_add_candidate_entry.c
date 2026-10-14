void __thiscall
ovl_add_candidate_entry(c1_ovl_resolution *ctx,c1_symbol *sym,c1_symbol *overload_set)

{
  byte bVar1;
  c1_ovl_candidate *pcVar2;
  int iVar3;
  c1_type *conv;
  
  bVar1 = sym->kind & 0x1f;
  if (((bVar1 == 8) ||
      ((bVar1 == 0x1a &&
       (iVar3 = sym_is_member_function_via_alias(*(c1_symbol **)sym->type), (char)iVar3 != '\0'))))
     && ((sym->kind & 0x1f) == 0x1a)) {
    conv = lookup_class_pointer_type
                     (*(void **)(*(int *)sym->type + 0x14),
                      (c1_u32)g_scope_vector->entries[*(short *)&sym->type->extra]);
    iVar3 = ctx->ncandidates;
    ctx->ncandidates = iVar3 + 1;
    if (ctx->candidates + iVar3 != (c1_ovl_candidate *)0x0) {
      pcVar2 = ovl_candidate_init(ctx->candidates + iVar3,&sym->kind,(int)overload_set,(int)conv,
                                  (int)(ctx->conversions + ctx->nconversions),(int)ctx->tail);
      ctx->tail = pcVar2;
      ctx->nconversions = ctx->nconversions + ctx->nargs;
      return;
    }
  }
  else {
    iVar3 = ctx->ncandidates;
    ctx->ncandidates = iVar3 + 1;
    if (ctx->candidates + iVar3 != (c1_ovl_candidate *)0x0) {
      pcVar2 = ovl_candidate_init(ctx->candidates + iVar3,&sym->kind,(int)overload_set,0,
                                  (int)(ctx->conversions + ctx->nconversions),(int)ctx->tail);
      ctx->tail = pcVar2;
      ctx->nconversions = ctx->nconversions + ctx->nargs;
      return;
    }
  }
  ctx->tail = (c1_ovl_candidate *)0x0;
  ctx->nconversions = ctx->nconversions + ctx->nargs;
  return;
}

