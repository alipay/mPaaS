import { CustomUIBuilderProvider, Page } from '@mpaas/hriver';
import { CustomUIBuilder, CustomUIBuilder0 } from './H5CustomTitle';

export class CustomUIBuilderProviderImpl extends CustomUIBuilderProvider {
  getCustomUIBuilder(): WrappedBuilder<[string, Page]> {
    return wrapBuilder(CustomUIBuilder);
  }
}

export class CustomUIBuilderProviderImpl0 extends CustomUIBuilderProvider {
  getCustomUIBuilder(): WrappedBuilder<[string, Page]> {
    return wrapBuilder(CustomUIBuilder0);
  }
}