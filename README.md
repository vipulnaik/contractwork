# contractwork

This repository contains details of contract work sponsored by Vipul Naik. The repository was officially created as a separate repository on Friday, December 9, 2016, forked from [working-drafts](https://github.com/vipulnaik/working-drafts).

See the [contributor cover summary](https://github.com/vipulnaik/contractwork/blob/master/contributor-cover-summary.mediawiki) for more details.

For a usable interface to understand all the contract work so far, see [Contract Work for Vipul Naik](https://contractwork.vipulnaik.com). The underlying code for that is in the [access-portal folder](https://github.com/vipulnaik/contractwork/tree/master/access-portal/) in this Git repository.

If you are a new contributor or contract worker who works on Wikipedia content creation, make sure to read Issa Rice's [Memo for Wikipedia editors who are starting](https://exp.issarice.com/wikipedia.html).

## Setting up

This section is for people who want to set up a local mirror of the contract
work portal (e.g. for development purposes).

Note that the `passwordFile.inc` file in `access-portal/backend/globalVariables` is excluded from the Git repository, but you can modify a corresponding dummy password file at [`dummyPasswordFile.inc`](https://github.com/vipulnaik/contractwork/blob/master/access-portal/backend/globalVariables/dummyPasswordFile.inc):

```bash
cp access-portal/backend/globalVariables/{dummyPasswordFile.inc,passwordFile.inc}
vi access-portal/backend/globalVariables/passwordFile.inc # change to add database login info
```

### Table sorting

To get files for table sorting, run:

```bash
make fetch_table_sorting
```

You can remove these files with `make clean_table_sorting`.

### AnchorJS

To get AnchorJS, run:

```bash
make fetch_anchorjs
```

You can remove these files with `make clean_anchorjs`.
