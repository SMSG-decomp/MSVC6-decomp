void __fastcall diag_run_context_notes(c1_diag_context *ctx)

{
  c1_diag_note_cell *cell;
  
  for (cell = ctx->context_notes; cell != (c1_diag_note_cell *)0x0; cell = cell->next) {
    (*cell->object->vtbl->note)();
    diag_queue_release_pending((int *)ctx);
  }
  return;
}

