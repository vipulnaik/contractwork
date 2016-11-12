---
title: Revisiting the “great decline” in Wikipedia pageviews
author:
  - Vipul Naik
  - Issa Rice
date: 2016-10-28
---

(This is a non-canonical copy).

We expect to publish this post in January 2017 and include data up to
and including December 2016.

# Summary

In March 2015 one of us (Vipul Naik) wrote ["The great decline in
Wikipedia pageviews"][great_decline_full] (called "the original post"
in this post).
This post reinvestigates that puzzle much more
thoroughly, using new, more reliable pageview data, Internet surveys,
and better graphing and visualization tools.

## The central puzzle and some answers

  * Have desktop pageviews (i.e., pageviews of Wikipedia pages from
    desktop devices) actually declined?  

    Short answer: Yes, they have declined by 50% overall since the
    early 2013 peak. 
    Specific page types have declined by between 20%
    and 80% since their respective peaks, which occurred between
    mid-2010 and early 2014.
    The magnitude of decline and the time of peak depend on the page
    type.

  * Why have desktop pageviews declined? And, have combined (desktop +
    mobile) pageviews declined, and if so, why?  

    Short answer: Substitution to mobile could explain between 10 and
    40 percentage points of the desktop decline.

    Inclusion/exclusion of non-human traffic could explain between 5
    and 20 percentage points of the desktop decline, with the effects
    of this concentrated in mid-2015, when the definitions were
    changed.
 
    Switch to HTTPS and the block of Wikipedia in China could explain
    up to 5 percentage points of the decline. This happened in
    mid-2015, and competes with the inclusion/exclusion of non-human
    traffic in explaining the jump at the time.

    After accounting for these explanations, the residual decline to
    explain is between 0 and 10 percentage points, or up to 20% after
    rebasing. 
    Some candidates to explain the residual are increased
    reliance on social media and search algorithm and usage changes.

  * Do people subjectively feel they are using Wikipedia less?  
    How do
    we square their subjective impressions with the stats?
    
    Short answer: People generally perceive either no change in use or
    say they don't use Wikipedia at all.
    But in a head-to-head comparison of "use more now" versus "use
    less now", the former wins.
    We have some explanation of what's driving the subjective
    impression, but nothing conclusive.

## Why is this important?

The [original post][great_decline_full] discusses several motivations for
looking at Wikipedia pageviews.
You can read that post for more details, but to summarize, Wikipedia pageviews
are useful as a way to understand:

  * what people are interested in learning about
  * the overall growth of the Internet

We have been interested in these topics and one of us (Vipul) has written
other articles such as ["How to Gauge the Popularity of a Topic
Online"][gauge_popularity_online] and ["How to Understand Your Website
Traffic Variation with Time"][traffic_var_time] on wikiHow.

A more recent motivation for us is the following.
As content creators and more recently as a [funder of content creation
work][cover_summary], one of the appeals of writing articles for Wikipedia is
that they receive more pageviews than if the same articles are hosted on
another site (such as a personal site).
However if Wikipedia's viewership is actually declining, this should
cause us to downgrade our estimate of the long-term value of content
creation on Wikipedia.

With that said, this post focuses on the specific question of
Wikipedia decline and does not discuss the implications given our
particular motivations.
That's because we expect the post to be of interest to many more
people than those who share our specific motivations.

We also hope that, even if the puzzle *per se* does not interest you,
the process we use to investigate it, and some of the findings we
obtain along the way, will ignite your interest.

### Getting more background

We keep this post as terse as possible while covering all the key
findings.
A lot more detail is available in the Appendix.

We also recommend that readers interested in diving deeper into the
timeline of events that we reference here read our [timeline of
Wikimedia analytics][ana].

# Our three-pronged evaluation strategy: total pageviews, per-page pageviews, and other metrics

To resolve the first question of our central puzzle, and to evaluate
hypotheses addressing the second question, we will evaluate in three
ways:

  * Total pageview data (summed up over all pages)

  * Per-page pageview data (considered separately by page, and summed
    up by page type for different definitions of page type)

  * Other metrics

## Total pageview data

Total pageview data, i.e. the summed pageviews of all pages within
each combination of language and access type (desktop, mobile), are
made available by the Wikimedia Foundation, the nonprofit that hosts
Wikipedia.

The data is available starting December 2007 for desktop, and starting
June 2010 for mobile (one year after the mobile site became the
default user experience for people on mobile devices).
In May 2015, the source for this data was changed, and started
excluding spiders.

For more on sources, see [Data sources for total metrics](#data-sources-for-total-metrics).

## Per-page pageview data

Looking at pageviews of specific pages is helpful for many reasons:

  * We can identify different trends based on the type of page: 
    As we'll see in this post, trends were very different for
    different types of pages.

  * We can control for new page creation, a confounder of
    total pageview statistics:
    For instance, we know (see the size of Wikipedia graph above) that
    the English Wikipedia expanded its number of pages from about 3.14
    million in the beginning of 2010 to over 5 million in the
    beginning of 2016.  
    That's a lot more pages for people to visit!
    So the presence of all these additional pages might itself
    increase traffic, even if traffic to existing pages remained
    stagnant.

  * We can understand the way a page's revision history could affect
    pageviews:
    We can understand the effect of phenomena such as redirects,
    merges, content migrated to another page, and changes to page
    length and quality.

We have per-page pageview data for the main site (desktop) from
December 10, 2007 to the present.
We have per-page mobile pageview data and a separation of human and
spider pageviews starting July 2015.
For more on the data sources we use for pageview counts for individual
pages, see [Data sources for page-level
metrics](#data-sources-for-page-level-metrics).

## Other metrics

This post focuses, as the title suggests, on the decline in
pageviews.
Other metrics people generally look at when looking at website
analytics include sessions (visits), unique pageviews, and users
(visitors).
Generally, these move in tandem with pageviews: when pageviews go up,
so do sessions, unique pageviews, and users. But this is not
guaranteed.

We don't have reliable data on most of these metrics, and we
have very limited page-level data for a few months.

In each evaluation of ours, we will consider the data we do have
available on these metrics to see if it helps us with the evaluation.

# Have desktop pageviews actually declined?

Upshot: Yes, both total (across all pages) and even more so for some
specific types of pages.

Let's apply our three-pronged evaluation to address this question.

## Total desktop pageview decline

We see a clear decline in total pageviews for the English Wikipedia.
The total desktop data is identified with a green line and labeled
"main site" in the graph below.  
For more details, see the [desktop stats published by the Wikimedia
Foundation][desktop_stats].

![Page views: 7,948 million per month = 265 million per day = 11.0 million per
hour = 184 thousand per minute = 3.1 thousand per second.
Metrics have been normalized to months of 30 days: Jan\*30/31, Feb\*30/(28|29),
Mar\*30/31, etc.
Plot by Erik Zachte.
Plot is in the public domain.](http://issarice.com/PlotPageviewsEN.png)

For the English Wikipedia, total desktop pageviews declined about 53%
from a peak in January 2013 of 9,044 million to a value of 4,211 million in
October 2016 (both numbers are normalized to 30-day month).

However, January 2013 was possibly an anomalous month. 

The Wikimedia Foundation itself [notes][desktop_stats]:

> Dec 2012 - Jan 2013: counts for last two weeks of Dec and first week
  of Jan were broken (much bogus traffic). Data for these weeks have
  been extrapolated from unaffected days.

For a fairer comparison, we therefore do two comparisons of
three-month periods. Note that we use the raw (unnormalized) numbers
here. Numbers are for desktop pageviews of the English Wikipedia:

  * April to June 2012, compared with April to June 2016: A drop of
    46% from 22,577 million pageviews in 2012 to 12,180 million
    pageviews in 2016.

  * September to November 2012, compared with September to November
    2016: A drop from 24,514 million pageviews in 2012 to (4124 + 4351
    + ?) million pageviews in 2016, of about 50%.

The reasons for selecting the time periods in this way are:

  * Control for the weekly cycle: Each of the periods being compared
    is 91 days long, which is exactly 13 weeks.
    Thus, they each sample equally from all days of the week.
    This controls for the weekly cycle in Wikipedia pageviews (more
    desktop traffic on weekdays).

  * Control for the annual cycle: For our comparison, we look at the
    same months of the year. Therefore, general annual trends (such as
    Northern Hemisphere summer dip), as well as specific holidays that
    cause traffic dips, are controlled for.

  * Control for the four-year cycle of United States elections: This
    isn't too important for overall traffic, but still a nice
    consequence of our selection.

Of this drop of between 46 and 50 percentage points, about 20
percentage points are explained by changes that occurred in the summer
of 2015, primarily the removal of non-human traffic from pageviews,
explained in the [non-human traffic](#non-human-traffic) section.
Other events around this time (the switch to HTTPS, and the blocking
of Wikipedia in China, could explain part of the 20 percentage points
of decline, and perhaps a few more percentage points.

We see similar magnitudes of decline in the other leading language
Wikipedias by traffic, namely Spanish, Russian, German, Japanese, and
French.  
In other words: a little over 50 percentage points decline
since a peak around January 2013, and between 45 and 50 percentage points
after doing a fairer comparison of three-month periods across years.
20 percentage points explained by summer 2015 changes (mostly the
exclusion of non-human traffic), and between 25 and 30 percentage
points (or, between 31% and 36% decline) remains unexplained.

A couple of other notes:

  * The Chinese Wikipedia itself saw a much sharper decrease in summer
    2015 compared to the other Wikipedias.
    The extra decline experienced by the Chinese Wikipedia is probably
    explained by the blocking of Wikipedia in China.

  * Small language Wikipedias experienced much more significant
    declines, but a larger share of the decline is explained by the
    exclusion of non-human traffic.

    In particular, they saw a bigger downward jump from April to May
    2015 when the data source began excluding spider traffic.
    For instance, 9 of the 10 lowest-traffic language Wikipedias saw a
    decline of over 50% in pageviews from April to May 2015, and all
    the top ten are currently seeing less than 25% of their peak
    pageviews.

## Per-page desktop pageview decline

Dealing with specific types of pages can help better understand where
the decline was sharpest and where it was slowest, control for new
page creation, and relate with the revision history of pages.

We have an overall decline benchmark of 50% to compare the decline of
specific pages against.

### Above-average decline page types

In general, we found that pages that deal with very general topics
experienced the largest declines, ranging from 60% to 85%.
Most of the pages we considered here had been around since before
2007, and were reasonably well-developed by then.
We will discuss the relative role of non-human traffic for these pages
later, but generally spiders affected the page-level pageview counts by
about 10 percentage points.

Some examples:

  * Colors (across languages): For instance, for the English
    Wikipedia, desktop pageviews of colors peaked at 901,872 in
    October 2012, compared to 185,375 in October 2016, for a decline
    of 79.6%.

    For the German Wikipedia, desktop pageviews peaked at 93,479 in
    March 2009 and were at 22,022 in October 2016, for a decline of
    76.6%.

  * Animals of various kinds, such as mammals, birds, reptiles, and
    insects: For each of these, we saw declines from the peak (in late
    2012 or early 2013) to the present value, with the percentage
    decline varying between 65% and 80%.

  * Countries, continents and sports: For these, we saw a decline of 65%
    since the peak, but the peak occurred much earlier, in late 2010.
    The decline relative to late 2012 and early 2013 was closer to 50%,
    comparable with the total decline.

    Sports did see an unusual spike in March and April 2015 to a level
    similar to the 2010 peak, primarily due to the Cricket World Cup
    (but for some reason, golf also had an unusual spike in April
    2015).
    Excluding these months, the trend looks quite similar to that for
    countries.

  * Culinary topics, such as eggplant dishes, tomato dishes, and
    potato dishes, saw drops of between 60% and 75% between their
    peaks in early 2013 and the present.

Excluding outlier months does not affect the analysis much, since the
peaks were spread over several months.

Moreover, most of these pages had no discernible annual cycle (with
the exception of sports pages seeing high interest during world cups),
and only a mild weekly cycle, so taking the annual cycle into account
also does not affect conclusions much.

All these page types are relatively timeless, so that there should not
be any intrinsic reasons for human interest in the underlying topic to
vary significantly over a few years.
This is most obvious for colors and animals.
For countries, continents, and sports, individual instances can become
topics of greater interest at specific times, but the total across all
pages of the type should not fluctuate much.

### Similar-to-average decline page types

  * Cities: The archetypal example here is cities, that peaked in
    March 2013 at about 12.85 million, compared to the present value
    of 5.3 million.  Since the peak month was a bit higher than others
    surrounding it, comparing with the average of the peak era is more
    reliable, and shows a decline of 55%, a little more than the
    decline in total pageviews.

    We see similar patterns for subsets of cities, such as Chinese
    cities and Indian cities.

  * Topics related to technology, including programming languages,
    Internet protocols, web development, and web browsers, also peaked
    in early 2013 and have since dropped by a little over 50%. [VERIFY]

### Below-average decline page types

  * Topics related to the nonprofit sector, such as philanthropic
    foundations and topics related to effective altruism.  

    These have either stayed constant (after accounting for seasonal
    cycles) or increased a bit.

  * Content in new formats, such as timeline pages.
    Already existing timeline pages saw a decline in pageviews, but
    the creation of many new pages of this type led to an overall
    increase.

  * Topics related to United States politics.

    This is likely a cyclical effect due to the 2016 United States
    election, which is attracting more attention than the 2012 United
    States election.

## Other desktop metric decline

One other data source that provides further weak evidence of a
desktop decline: the [unique visitors data][comscore_uniques] reported
by comScore till May 2015, that includes only desktop users.
This data shows a peak in North America as well as globally in the
third quarter of 2013, a sharp decline over the next 12 months in
North America, and a subsequent partial rebound.
Part of the data, capturing the peak and the subsequent decline (but
not the rebound) was discussed in a [September 2014
report][comscore_wmf_sep14] published by comScore and the Wikimedia
Foundation.
Starting January 1, 2016, the Wikimedia Foundation's own Unique
Devices Dataset is available, but this is not directly comparable with
comScore's data.

There is also data from [SimilarWeb][similarweb_evolving] estimating a
decline in search traffic to Wikipedia.
This data is a little more indirect and complicated to evaluate, so
we'll return to it when we examine search-related hypotheses for the
decline.

# Why have desktop pageviews declined? And, have combined desktop + mobile pageviews declined? And if so, why?

## Taxonomy of hypotheses

There are a lot of hypotheses, so we'll group them in five broad
categories:

  * Substitution hypotheses within Wikipedia: This includes shift to
    mobile and language substitution.

  * Measurement issues: This includes non-human traffic, changes to
    pageview definition, and redirects.

  * Less inbound interest and traffic: This includes hypotheses
    related to search behavior and algorithm changes, improvement in
    alternative knowledge sources, increased reliance on social media
    (that is less likely to send traffic to Wikipedia), and increased
    use of smart personal assistants to answer quick questions.

  * Reduced user faith in Wikipedia: Users consider Wikipedia less
    reliable, comprehensive, or useful, or find it harder to
    understand now.

  * Internet censorship changes, specifically, the Internet censorship
    of Wikipedia in China following the switch to HTTPS.

Within each category, we will list the hypotheses in decreasing order
of their importance as it will finally emerge.

After listing all hypotheses, we will then proceed to evaluating each
hypothesis using our three-pronged evaluation strategy.
Once we are done with that, we will consolidate our findings to
estimate how the entirety of decline should be apportioned between
different hypotheses.

### Substitution hypotheses

There are two main substitution hypotheses:

  * Shift to mobile: 
    Explains some of the desktop decline, but not all. 
    Lack of per-page mobile data before July 2015 leaves some
    indeterminacy.

  * Language substitution: 
    Unlikely to be a factor, since the page types we checked saw
    similar decline trends across languages.

### Measurement issues hypotheses

  * Non-human traffic: Nonnegligible but still minor relative to the
    magnitude of the decline.  
    Can be one of many contributing factors.

  * Changes to pageview definition:
    Aside from the inclusion or exclusion of spiders (covered above), too
    minor.

  * Redirects:
    Unlikely to affect the overall picture, but may be relevant to
    specific pages.

  * Other site changes:
    These include the switch to HTTPS, redirection of tablets to
    mobile sites, and others.
    Our analysis did not find significant effects of these.

### Less inbound interest and traffic

  * Increased reliance on social media:
    This could well be a factor, and we list some reasons but can't
    quantify the effect.

  * Decline in search engine results page (SERP) ranking of Wikipedia:
    Unclear whether this even happened!
    Looking at search referral traffic paints a mixed picture.

  * Google Knowledge Graph:
    Looking at timing and referral source information paints a mixed
    picture.
    However, looking at the pages with the most decline gives mild
    support to the theory.

  * Alternative knowledge sources:
    Growth of specialized knowledge sources.
    Possibly a factor, but hard to quantify and also to cleanly
    separate from the other factors

  * Other means of indirect access, such as digital assistants such as
    Siri:
    Likely not a direct factor in desktop decline, since Siri and
    other digital assistants were mobile-focused.  


### Changes in user perception of Wikipedia

Changes in user perception could be driven by actual changes on
Wikipedia, or by changes in the narrative surrounding it (regardless
of objective truth).

  * Page quality changes:
    No evidence that this was a factor, and tentative evidence against.

  * Changes in people's overall impression of Wikipedia's reliability
    and utility

### Censorship

  * Internet censorship in China, in summer 2015, in response to
    Wikipedia switching over to HTTPS making page-level blocking
    harder.

We will now examine the hypotheses one by one.

## Evalation of hypotheses

### Shift to mobile

Upshot: Explains somewhere between 5 and 40 percentage points out of
the 50 percentage point decline in total desktop pageviews.
The proportion explained depends on the page type.
Lack of mobile pageview data before July 2015 means we can't calculate
the substitution effect exactly, so we present bounds on the effect.

A leading hypothesis for the decline in desktop pageviews is that
these pageviews just migrated to mobile.

One extreme assumption (that we call "maximal substitution") is to
explain as much of the desktop pageview decline using mobile as
possible. 
Explicitly, if desktop pageviews declined by X and mobile pageviews
increased by Y, then min{X, Y} pageviews moved from desktop to mobile,
and the residual is the unexplained component.
In our case, Y < X, so basically we'd say that all of the mobile
increase came from a desktop decline, but there is still some
unexplained desktop decline (of X - Y).

The other extreme view is that even though mobile pageviews increased
while desktop pageviews declined, none of the mobile pageview increase
came from the desktop decline.  
In other words, the users and use cases for mobile Wikipedia use did
not overlap at all with the users and use cases for the lost desktop
Wikipedia use.

The truth probably lies somewhere in between.
To estimate where it lies, therefore, it's not enough to simply look
at the total changes in desktop and mobile pageviews, but to dig into
more detail, including per-page data and time series data (i.e.,
looking at the precise timing of the changes).

Let us take a look at this hypothesis using our standard modus
operandi: total pageviews, per-page pageviews, and other metrics.

#### Total pageview decline and shift to mobile

![Page views: 7,948 million per month = 265 million per day = 11.0 million per
hour = 184 thousand per minute = 3.1 thousand per second.
Metrics have been normalized to months of 30 days: Jan\*30/31, Feb\*30/(28|29),
Mar\*30/31, etc.
Plot by Erik Zachte.
Plot is in the public domain.](http://issarice.com/PlotPageviewsEN.png)

We had previously selected two three-month comparisons between 2012
and 2016 when judging whether there has been a desktop decline.
Let's return to the same comparison, but now looking at total data.
Totals may be off by a million in either direction because of rounding.

  * April to June 2012, compared with April to June 2016:

    ** English language desktop pageviews declined 46% from 22,577
       million in 2012 to 12,180 million in 2016.

    ** English language mobile pageviews increased 196% from 3,394
       million in 2012 to 10,038 million in 2016.

    ** English language total pageviews decreased 14.5% from 25,972
       million in 2012 to 22,217 million in 2016.

    ** Assuming maximal substitution, switch to mobile explains 6,644
       million out of the 10,397 million pageviews of desktop decline.
       That is 64% of the decline, or 29.4 percentage points out of
       the 46 percentage points that need to be explained.

  * September to November 2012, compared with September to November
    2016 (fillin). A smaller fraction is explained here.

The following qualitative conclusions hold across languages:

  * Mobile pageviews grew fairly quickly till December 2014 in all
    languages, and have stayed mostly stable in all languages since
    then.
    The values can be anywhere between double and four times the
    values in early 2013.

  * The present ratio of mobile to desktop pageviews in most
    leading language Wikipedias varies from 75% to 150%.

  * For most leading languages, substitution to mobile can explain
    between half and two-thirds of the total desktop decline (assuming
    maximal substitution). 
    Explicitly, it can explain between 20 and 35 percentage points out
    of a decline of between 40 and 55 percentage points (exact
    magnitudes depending on precise time intervals of comparison).

  * For the language Wikipedias with the lowest traffic, the exclusion
    of bots significantly cut down on mobile traffic in the same way
    as it cut down on desktop traffic.
    Due to the overwhelming role of bots in explaining the decline,
    it's hard to isolate the role of mobile.

#### Per-page pageview decline and shift to mobile

The story for per-page pageviews is harder to definitely infer,
because we have per-page mobile pageview data only from July 2015,
well after much of the desktop decline had finished.

Nonetheless, we can use the limited data to obtain a partial
classification of page types as follows:

* Definite declines: 
  These are page types where the combined (desktop + mobile) pageviews
  since July 2015 are less than the earlier desktop-only peak.

  For these pages, despite not knowing anything about mobile pageviews
  before July 2015, we can be confident their pageviews declined even
  after considering substitution to mobile.

  It turns out that the page types that are definite declines mostly
  overlap with the page types that we previously described as
  above-average declines.  

  Examples are colors, animals, countries, continents, and sports.

* Ambiguous cases (probably declines): These are page
  types for which the combined (desktop + mobile) pageviews since July
  2015 are greater than the previous desktop-only peak, but the
  desktop pageviews along are less than the earlier peak.

  In such cases, whether there has been a combined decline depends
  crucially on what the mobile pageviews looked like before July 2015,
  information we don't have.

  However, using total pageviews across all pages as a prior, we
  obtain that there has likely been a decline for such pages.

  These ambiguous cases overlap with the similar-to-average declines
  discussed earlier.
  Examples include cities and programming languages.

* Definite non-declines: These are page types for which the combined
  (desktop + mobile) pageviews since July 2015 exceed the previous
  desktop-only peak by a significant margin, and the desktop pageviews
  alone either stayed the same or declined only a little bit.

  These overlap with the below-average declines discussed earlier.
  Examples include philanthropic foundations, timelines, and topics
  related to effective altruism.

#### Shift to mobile in other metrics

Page 5 of the [comScore report][comscore_wmf_sep14] shows that while
unique visitors on desktop were declining in the United States, unique
visitors on mobile stayed largely constant, and by July 2014, even
overtook unique visitors on desktop.

We also see substitution as a general theme of other reports on the
evolution of the Internet in the United States and in the world at
large, as described in the "Understanding the Long-Term Trends for
Your Site" section of [How to Understand Your Website Traffic Variation
with Time][traffic_var_time].

### Language substitution

Upshot: No, language substitution is not an explanation.
In fact, specific page types show similar trends across languages,
rather than showing the opposite trends we'd expect if people are
substituting from one language to another.

Much of our analysis is focused on the English Wikipedia, so that
leads to a natural question: are people just switching away from the
English Wikipedia to other language Wikipedias?

#### Total pageview decline: consistent across major language Wikipedias, slightly slower on minor Wikipedias

As we discussed earlier, the total desktop pageview decline pattern
seen in the English Wikipedia is also seen in the other major language
Wikipedias: Russian, German, Spanish, Japanese, and French.
The trends are a little different on the other language Wikipedias,
but on none of the major language Wikipedias do we see any trend that
would be strong enough to cancel the decline on the English Wikipedia.

Here's a qualitative summary on trends by language:

  * Desktop pageviews peaked in 2013 for most of the top languages,
    and the current value is lower than the peak by somewhere between
    50% and 65%.  
    If anything, the English Wikipedia declined less than many of the
    language Wikipedias.
    The Chinese Wikipedia is somewhat unusual in the sense of having a
    late peak (September 2014) and declining as much as 67% since the
    peak.
    The unusual pattern of the Chinese Wikipedia is probably explained
    by the blocking of China from accessing Wikipedia in summer 2015,
    in response to Wikipedia's shift to HTTPS.


#### Per-page pageview decline

Across a variety of page types, we verified that the pageview trends
look the same for different language Wikipedias.

For instance, trends for pageviews of colors (both desktop-only and
combined desktop + mobile) look the same across the English, French,
Spanish, German, Japanese, Russian, Portuguese, Polish, Dutch,
Finnish, Hindi, and Korean Wikipedias (do they?).

These results are consistent with [previous
research][comparing_global_local] on the extent of substitution
between the English Wikipedia and other language Wikipedias.

### Non-human traffic

#### Total desktop pageviews and non-human traffic

In May 2015, the Wikimedia Foundation changed its
[reporting][desktop_stats] and started excluding non-human traffic
from pageview counts.

There was a decline in normalized monthly traffic from April to May
2015 of 20%.
Assuming the entirety of the decline is explained by the data source
change, we therefore get an estimate that non-human traffic accounts
for 20 percentage points out of the decline.

However, there is an important caveat: Wikipedia appears to have been
blocked in China in May 19, 2015, in response to the Wikimedia
Foundation's announcement of a switch to HTTPS (although the actual
switch occurred in June).
This has its biggest effects on the Chinese Wikipedia, whose traffic
dropped by about half as a result of the change.
However, it could also have had a small effect on the English
Wikipedia.
If so, then that would take away a few percentage points out of the 20
percentage points we currently attribute to non-human traffic.

Put 2012 and 2016 comparisons, now including mobile and bots

The conclusions are broadly similar across the other language Wikipedias:

#### Per-page desktop pageviews and non-human traffic

A heuristic is that non-human traffic accounts for 20% of pageviews.
While reasonable on the whole, this heuristic sweeps under the rug the
fact that non-human traffic does not move smoothly in sync with human
traffic.
Two key observations:

  * The proportion of traffic to a page that is non-human goes up as
    total pageviews go down.
    In particular, for pages with less than 100 pageviews, non-human
    traffic can account for anywhere between 20% and 80% of pageviews.
    At this scale, the magnitude of non-human traffic is affected more
    by aspects such as the number of inbound links than actual human
    interest.

  * 

Comparison with historical per-page data, however, runs into another
problem: previous data missed a lot of pageviews due to infrastructure
logging problems.

Between July and December 2015, we had human desktop pageviews
according to the Wikimedia pageviews API, human (desktop + spider)
pageviews according to the Wikimedia pageviews API, and pageviews from
stats.grok.se (based on the historical pagecounts-raw dataset, for
which data is available since December 2007).

By comparing these, we found that:

Human desktop pageviews according to pageviews API < pageviews according to stats.grok.se < (Human + spider) desktop pageview according to pageviews API

The gaps varied heavily by page type but roughly, each was about 10%:
pageviews according to stats.grok.se were 10% more than human desktop
pageviews, and (human + spider) desktop pageviews were 10% more than
pageviews according to stats.grok.se.

The upshot is that, when looking at per-page pageview data, non-human
traffic explains 10 percentage points out of the total decline in
pageviews between data prior to July 2015 and data after July 2015.

After accounting for the effect of non-human traffic, we can revisit
our earlier classification:

* Definite decline page types: These are page types where the peak for
  desktop + mobile + spider pageviews since January 2016 is lower than
  the previous desktop-only peak.

  The addition of spiders doesn't change qualitative conclusions for most
  page types, so this list is mostly the same as the definite decline
  page types before accounting for spiders.
  In turn, it's mostly the same as the above-average decline page types.

* Ambiguous cases:
  These are page types where desktop-only and desktop + spider pageviews
  saw a decline but desktop + mobile + spider did not.

  These mostly coincide with the ambiguous cases without accounting
  for spiders, though it does push a few page types from definite
  declines to ambiguous cases, and a few from ambiguous cases to
  definite non-declines.

  Accounting for spiders also pushes some ambiguous cases in the
  direction of less likely to be declines (phrase better).

* Definite non-declines: 
  These are page types for which the desktop +
  spider pageviews since July 2015 are comparable to or higher than
  the previous desktop-only numbers.

  We get a few more definite non-decline cases than earlier, as some
  of the previously ambiguous cases become non-declines.

A few other qualifiers are worth adding about the nature of the effect
of non-human traffic:

  * 


#### Other metrics and non-human traffic

Other metrics (such as comScore and SimilarWeb reports) attempt to
filter out non-human traffic throughout the time range for which they
have data available.
Therefore, they cannot be used to verify the proportion of traffic
that is non-human.

### Other measurement issues hypotheses: changes to pageview definition, redirects, and HTTPS

We looked for sudden changes in both total pageview counts and
per-page pageview counts at and around the times that specific changes
to pageview definitions and the HTTPS rollouts occurred.

Other than the large-scale removal of spiders, discussed in the previous
section, we did not see any statistically clear effects of any of the
other definition changes, either on total pageviews or per-page
pageviews.

For more on the points in time we looked at, you can take a look at
the [timeline of Wikimedia analytics][ana].

### Increased reliance on social media

Other than the move from desktop to mobile, one big change in people's
Internet consumption in the past few years is an increase in use of
social media, not just for interacting with friends, but also as a
source of information and news.

The type of content people consume in a social media-driven world is
determined not just by what they are interested in reading about, but
also by what their friends and pages they follow are interested in
sharing.
In particular, the propensity of a piece of content to get shared
affects the number of pageviews it receives.
Moreover, content that is written by people or organizations who have
an active social media presence is likely to get posted reguarly and
get more shares.

All these considerations lead to a negative relation between social
media use and Wikipedia pageviews.

This negative relation can be verified by comparing the ratio of
shares to pageviews for Wikipedia pages with non-Wikipedia pages.
Wikipedia pages consistently have much lower ratios of shares to
pageviews, by two or three orders of magnitude.

#### Total pageview data and social media

Do we have anything meaningful to say here?

#### Per-page pageview data and social media

One prediction of our theory is that the exceptions to the rule,
namely, the pages that people do like to share to Wikipedia, have seen
the least decline.
We find the prediction to be borne out by facts, but that's
not decisive evidence for the theory since many other theories could
yield the same prediction.

Unfortunately, we lack time series data for social media: we don't
know anything about people's social media engagement with a Wikipedia
page during a specific month.
The main social media data we have is cumulative shares recorded in
the months of October, November, and December 2016, collected using
the Facebook API.

To better understand the relation between social media and Wikipedia
pageviews, we define the following metric associated with a page:

Social media shareability = (Facebook share count) / (Cumulative number of Wikipedia desktop pageviews)

We will express social media shareability in units of 1/million, in
which case the values will range from single digits to a few thousand.

Our key findings:

  * For most pages, the social media shareability is between
    20/million and 100/million, with the median around 40/million.

  * Page types for which we saw average or above-average declines tend
    to have social media shareabilities below 100/million. For
    instance, colors, birds, and cities have a social media
    shareability of 40/million, whereas mammals and reptiles have
    values in the single digits.

  * Page types for which we saw below-average declines tend to have
    social media shareabilities of above 100/million.
    For instance, the value for programming languages is a little over
    100/million and that for philanthropic foundations is a little over
    200/million.
    Politics-related topics have much higher shareability (several
    hundred or even a few thousand per million, depending on the
    nature of the article) and have seen slower decline, though the
    2016 United States election is a major confounder here

#### Other metrics and social media

We don't really have any data here, do we?

### Search behavior and search algorithm changes

Our usual three-fold analysis fails for search behavior because we
have no reliable data on total pageviews or per-page pageviews driven
by specific referrers.

Nonetheless, we can carry out informed speculation for each part of
our evaluation, after outlining a theory of search behavior backed up
by other evidence.

We can break down changes in search referral traffic to Wikipedia into
the following different pieces:

  * People's propensity to use search engines (as opposed to directly
    visiting sites) to answer questions.

  * People's search behavior, and in particular the types of search
    queries they enter.
    Search queries that simply include an encyclopedia-worthy term or
    relationship would lead people to Wikipedia pages, whereas search
    queries of a more complex nature would lead people to specialized
    sites, and action-oriented search queries would lead people to
    action-oriented sites (not Wikipedia).

  * The ranking of Wikipedia pages in Google's Search Engine Results
    Pages (SERP), holding the underlying query constant.

  * People's propensity to click on Wikipedia pages, if they do show
    up in the results.

These four pieces aren't completely independent, but listing them out
separately allows for a cleaner examination of what's going on.

#### How has people's propensity to use search engines changed over time?

Upshot: Seems to have gone up, but increase is driven by mobile.

##### Estimates of total search volume, plus search volume by device type
    
Google Search is the dominant player, so getting a sense of their
numbers gives us a good overall sense of search growth.
According to [Search Engine Land's cobbling together of various
number][sel_search_growth], the annual number of Google searches has
grown from 365 billion+ in 2009 to 1.2 trillion in 2012 to over 2
trillion in 2015.
These numbers are based on non-uniform information snippets released
by Google in vague language, so they may not be accurate
interpretations.

It also seems, based on comScore data cited in the blog post, that
people's desktop search use has basically flatlined.
Therefore, much of the increase in search volume is driven by mobile
devices.

##### People's subjective impression of how much they use search

We have data from some surveys conducted through SurveyMonkey.  The
results are below.  The question asked people to compare their use of
Google Search now versus earlier (in 2011).  The full questions can be
seen in the [Surveys](#Surveys) section.

Response             S1Q2SM (N=52)   S1Q2V (N=27)   S2Q7SM (N=58)    S2Q7UW (N=42)
-----------------    -------------   ------------   -------------    -------------
not now; not 2011               0%           3.7%            3.4%               0%
now; not 2011                 3.8%             0%           17.2%             2.4%
not now; 2011                   0%             0%            1.7%             2.4%
now; 2011 (same)             23.1%          70.4%           32.8%            40.1%
more now                     73.1%          25.9%           43.1%            47.6%
less now                        0%             0%            1.7%             7.2%

For the sampled audiences, we see that the most people use Google
Search now and used it in 2011, and use it either the same or more
now.
Overall, people seem somewhat more inclined to say they use search
more now.

(Also doing GCS and will update with results)

#### Changes in search behavior (i.e., types of search queries)

A [SEO by the sea blog post][search_behavior_change] has an extensive
list of research conducted on people's search patterns.
Much of the cited research is point-in-time research: it uses various
kinds of observation (search query logs, toolbar data, or explicit
tasks given to users) within a narrow time slice.
However, comparing studies done at different points in time, as well
as looking at the results of the studies in conjunction with what we
know about how other things changed, allows us to make informed
speculation on the changes in search behavior.

##### User experience and query specificity

Experienced searchers are likely to include more specific and narrow
search queries, whereas novice searchers are likely to include broader
search queries.  
This was reported in [Aula 2003][aula_03], that studied the
correlation between queries used and searcher characteristics.

A [2008 paper by Microsoft Research][msr_08] gave an illustrative
example of how this narrow/broad distinction could specifically apply
to Wikipedia pages.
The example was described in "Table 1. Sample session" in the paper.
In the example, a user first searches for peanut butter, and is shown
the Wikipedia page on the subject, that the user clicks.
The user then clicks to the Wikipedia page on sandwich.
The user then returns to the search engine and requeries peanut butter
sandwich recipes, and gets to a recipe site.

It is possible that visiting the Wikipedia page provided the user
useful information that helped the user identify the relation between
peanut butter and sandwich, and led to the next query.
However, it seems more believable that the user had prior intent to
look up peanut butter sandwich recipes.
A more experienced user may have directly queried for peanut butter
sandwich recipes.

In other words, experienced users are more specific, and it seems
plausible that specific queries tend to be ones where Wikipedia is
less valuable.
This could be because the queries are action-oriented or
how-to-oriented, or it could be because the topics in question fail to
meet Wikipedia's notability criteria.

How could this relate with time?

We know that people's use of search engines has stayed the same or
gone up, and in particular, their accumulated experience using search
engines has gone up!

As a result, more users are likely to behave like experienced users,
which could lead them to enter fewer of the simple starting queries
such as "peanut butter".

#### The role of mobile devices

We have an estimate that desktop search volume has flatlined over the
last few years, whereas mobile search volume grew a lot.


### People's conditional probability of clicking on Wikipedia if it shows up

It seems that people have a strong tendency to click on whatever is at
the top of search results.
It's not clear that this tendency has changed significantly.

Insert results of eye-tracking studies: http://searchengineland.com/new-google-eye-tracking-study-shows-downfall-golden-triangle-205274

http://www.seobythesea.com/2010/05/google-studies-how-search-behavior-changes-when-searchers-are-faced-with-difficult-questions/

An entire industry of search engine optimization (SEO) is built around
a simple idea: the ranking of a webpage on search engine result pages
(SERPs) has a huge effect on how much people visit the webpages.
So, it seems that if, for whatever reason, Google's algorithms pushed
Wikipedia pages down in SERPs, that would cause a decline in search
referral traffic to Wikipedia.
Further, such a decline might be self-reinforcing: as people visit
Wikipedia pages less due to the search rank decline, they become less
likely to link to it, share it, or otherwise engage with it, which
might lead search engines to demote Wikipedia pages further.

We don't have clean comprehensive page-level data on search referral
traffic to test this hypothesis.
Nor do we have systematic historical SERP data for individual search
terms.
However, there are a number of other approaches we can use.

  * Trends in overall search referral traffic:
    The Wikimedia Foundation has released some overall
    data on search referral traffic.
    Third parties, such as SimilarWeb, also estimate this number.
    We can look both at changes in the absolute volume of search
    referral traffic and changes in its relative share.

  * Timing: We can look at specific search algorithm changes made by
    Google and see if these coincide with declines in pageviews of
    pages we expect to be affected by those algorithm changes.

  * SEO commentary and studies on the effect of search algorithm
    changes made by Google, especially those that discuss the impact
    on Wikipedia.
    In particular, there are a few analyses of how Wikipedia rankings
    changed on SERPs after Google's search algorithm changes.

Note that the Knowledge Graph, discussed as the next hypothesis, would
produce some very similar symptoms, so some evidence that might
support this hypothesis can also be construed as evidence for the
Knowledge Graph.

### Trends in overall search referral traffic

We can look at trends (i.e., changes over time) in:

  * Total search referral traffic from search engines (primarily
    Google Search) to Wikipedia.
    We'd ideally like information both on the number of visits and the
    number of pageviews that occurred in sessions started by such
    visits.

  * Search referral traffic as a fraction of overall traffic.
    We'd ideally like the fraction both for visits and for pageviews.

  * Search referral traffic as a fraction of overall traffic, compared
    with trends for general Internet behavior.
    There may be general changes across the Internet in the extent to
    which people use search engines (rather than direct visits) to
    find content.
    Therefore, when looking at the changes in the fraction of search
    referral traffic to Wikipedia, we should benchmark against these
    general trends.
    This point is somewhat subtle and is explained more later.

Let's see what data we have on these fronts.
On August 17, 2015, Oliver Keyes published a report on the percentage
of traffic to Wikipedia that came from Google.
This covers all language Wikipedias (and maybe also other Wikimedia
Foundation-owned websites).
For privacy reasons, the Wikimedia Foundation does not track sessions,
and therefore cannot answer questions around the proportion of visits
that came from search.
The write-up includes data from January 1, 2015 to August 1, 2015.
Some key findings:

  * Identifiable Google referral accounted for 33% of pageviews in
    January 2015, and grew to 36% of pageviews by August 1, 2015.
    Growth was gradual, with some flatlining from mid-March to
    mid-April.

    Traffic with no referral (which could be a mix of genuinely direct
    traffic and search referral traffic where the referrer got hidden
    for security reasons) fell from 26% of pageviews in January 2015
    to a little under 24% by August 1, 2015.

    If the identifiable Google search and no referral traffic were
    combined, you'd still see a slight increase in the percentage
    of traffic.

  * In absolute terms, pageviews being referred by search *fell*.
    The reason the proportion went up is that other pageviews fell
    even more.

Though it's not totally clear, the conclusion about absolute search
traffic is the more important one here.
It shows that Google is driving fewer people to Wikipedia on the
whole.
This could be driven by a few different possible factors:

  * People became less inclined to search for the sorts of keywords
    for which Wikipedia shows up as a top result.

    For instance, people's queries could have become more specific and
    granular, or more action-oriented, to the point that a
    general-purpose knowledge-focused resource wouldn't be able to
    meet them.
    

## Indirect access: Google Knowledge Graph

Upshot: Maybe, but if there's an effect it's probably even more
indirect than you'd think!

One possible explanation of the decline of Wikipedia discussed in the
[previous post][great_decline_full] was the [Google Knowledge Graph][gkg_wiki].
The Knowledge Graph was also cited as a reason for the decline in
Google referral traffic to Wikipedia in August 2015 in [commentary by
SimilarWeb][similarweb_evolving], as well as in much of the media
coverage based off of that commentary.

The Knowledge Graph is Google's internal knowledge base, capturing
semantic relationships between topics.
Card-like displays based on the Knowledge Graph (variously called
"knowledge panels" and "knowledge cards") began to be displayed on
Google search engine results pages (SERPs) starting May 16, 2012 in
the United States for English-language searches.
You can get a fairly detailed account of how these knowledge panels
looked like upon launch in the [Search Engine Land post announcing the
launch][gkg_sel].
On December 4, 2012, the Knowledge Graph was introduced in seven more
languages: Spanish, French, German, Portuguese, Japanese, Russian, and
Italian.

Here's the crude theory of how the Knowledge Graph could result in
decline to traffic to Wikipedia.
Let's say you hear a name, say "Christina Perri", that seems vaguely
familiar but you're not able to place it.
You just want to figure out roughly who this person is (an actress? a
politician?)
Previously, you might have Googled the name, then clicked through to
her Wikipedia page and figured out who she was.
Now, you'd Google, but you'd be presented with a nice knowledge panel
summarizing who she is, including photos, and giving links to related
people and topics.
The information presented in the knowledge panel might suffice for
your curiosity, and you would no longer feel the need to click through
to her Wikipedia page.

Quoting from [SimilarWeb's explanation][similarweb_evolving]:

> Google’s Knowledge Graph boxes which aims to provide direct answers
> within the search results. Our hypothesis is that a significant part
> the declines are due to changes made by Google which reduce the
> traffic sent to Wikipedia through providing information from
> Wikipedia in the search results. We would ask if this is fair – does
> improving the user experience on Search justify cannibalizing
> traffic to the publishers who produce that content – thereby
> disrupting their ecosystems (for profit or otherwise). It’s possible
> that the Knowledge Graph is also decreasing direct traffic as people
> may prefer using search to get direct to the data they want vs going
> to Wikipedia.

Let's say this was the causal mechanism.
How would we expect to see this reflected in the data?
We'd look for the following:

  * Timing: Traffic declines would be sharpest close in time to the
    Knowledge Graph rollout.

  * Referral sources: Traffic declines would be sharpest for referral
    traffic from Google.

  * Pages: Traffic declines would be sharpest for the pages for which
    Google started showing knowledge panels.

Let's examine each of these hypotheses carefully.

### Timing: does the introduction of knowledge panels match the decline?

Knowledge panels rolled out for the English language in the United
States in May 2012, and were gradually rolled out to the rest of the
world over the next few months.

The United States [accounts for about
40%][en_wikipedia_stats_by_country] of traffic to the English
Wikipedia.  
It appears that knowledge panels, as they existed on May 16, 2012 (the
official announcement date) were [pretty close in form and structure
to their present incarnation][gkg_sel].
Thus, any changes that arose as a result of the Knowledge Panel should
have started showing up in the English Wikipedia's aggregate
statistics around May 2012.
And if the May 16 date was the actual date of rollout to most of the US, then
we should see a sharp change in the period surrounding May 16.

The data doesn't support either of these.

  * Overall desktop pageviews peaked in early 2013, much after May 2012.

  * Very few tags peaked in May 2012 or right before. 
    As you can see from the picture, a lot of peaks happened in late
    2012 and early 2013, and many happened in 2011, but very few
    happened around the time the Knowledge Graph was introduced.

  * A more granular look at pageviews by day for May 2012 fails to
    show any significant changes close to May 16.
    For instance, take a look at the [May 2012 stats.grok.se results
    for black][sgs_black].

The data is not very favorable to the Knowledge Graph hypothesis but doesn't rule it out.
Some ways of reconciling it:

  * The effect of the Knowledge Graph was stronger in the regions
    and populations among which it was rolled out later.

  * Behavior change as a result of the Knowledge Graph has a lag.
    People may not initially pay attention to the Knowledge Graph, but
    over the course of several months may get used to it.

  * There was a feedback loop at play, creating a lag.
    People liked knowledge panels, and since these results
    competed most directly with Wikipedia pages, they were a little
    less likely to click on Wikipedia.
    Google saw this and pushed Wikipedia further down in the search
    engine results page (SERP), causing traffic to Wikipedia to
    decline further.
    
  * There were subtle improvements to the quality of the knowledge
    panels over time, and the knowledge panels got good enough to
    start substituting for Wikipedia only in late 2012 and early 2013.
    I am doubtful of this, primary because the [Search Engine Land
    post announcing knowledge panels][gkg_sel] seems to suggest that
    the state of knowledge panels at launch was pretty close to what
    it is now.

### Referral traffic: is the share of Wikipedia traffic coming from Google declining?

(TODO: This section isn't really about the knowledge graph. Should it be
moved elsewhere?)

In August 2015, SimilarWeb published a series of posts discussing its
observation that the volume of traffic to Wikipedia from Google was
fairly low in summer 2015.
After some back and forth with the Wikimedia Foundation, SimilarWeb
came to the [following conclusions][similarweb_evolving]:

  * The decline in traffic from search engines had been gradual,
    rather than a sudden summer decline.
    The reason SimilarWeb had gotten confused was that in the summer,
    the overall decline trend was further accentuated by the annual
    summer dip.

  * Data from the Wikimedia Foundation showed that even though the
    total volume of traffic to Wikipedia from Google Search declined,
    the share of Wikipedia's traffic coming from Google didn't
    decline, because non-Google traffic declined even more.

### Pages: do we see stronger declines in pages for which knowledge panels exist?

The tentative answer is yes, but this is less conclusive than it
seems, because these pages also tend to be ones whose views are more
likely to migrate to mobile devices.

There is no way (as far as we are aware) of looking up when knowledge
panels started showing up in search results for specific search terms.
However, going by the description in the [Search Engine Land post
announcing the launch][gkg_sel], it seems likely that all pages for
colors, countries, and major cities would have been covered by
knowledge panels during the official launch in May 2012.

However, these "popular" page types share other characteristics, such
as a high mobile-to-desktop ratio (that would make substitution to
mobile a likely cause of a desktop decline.
Therefore, we can consider this at best very mild evidence that
knowledge panels played a role in page decline.

## Other hypotheses


  * Could browsers like Opera Mini be adding pageviews as spiders?
    See the ["analytics and proxy/remote browsers"][opera] thread on the
    Analytics mailing list.
    Probably not.

## Search engine rankings

  * Wikipedia showing up less in SERPs? → Try to get access to historical
    SERPs for some search queries.
    This actually seems harder to obtain than we first thought.

## Redirects

Could a change in redirects have anything to do with this?
For instance see ["Consider the Redirect"][ctr]:

> Because viewers don't see redirects, viewing a redirect is
> substantively different from viewing a normal page. For example, if a
> user visits the article on "Seattle, Washington", this will be
> recorded as a view to the redirect even though the target article
> "Seattle" is displayed. In this sense, views of redirects will tend
> to be overcounted while views of target articles will tend to be
> undercounted.
>
> [...]
>
> Because redirects are edited infrequently but "viewed" as often as
> millions of times per month each, redirects may be contributing to
> the surprisingly low correlation between edits and views noted by
> Priedhorsky et al. and others.

See also ["Analytics/Data/Redirects -- Wikitech"][redirect_spelling]

Could people somehow be viewing redirects more than the actual pages,
compared to 2011--2013?
To give one recent example (too recent to matter), the Wikipedia
article ["New York"][ny] is about the state, not the city.
However there is a [recent shift][ny_disc] to change all wikilinks
`[[New York]]` to go through the redirect page
["New York (state)"][ny_state], with the wikilink
`[[New York (state)|New York]]`.
This means that less pageviews will be recorded for the New York page,
and more will be recorded for the redirect page.
One idea is that if a sufficiently large number of highly popular pages
have similar sorts of redirection manipulation, the pageviews for the
article itself could be going down even while people are reading the
page more -- the pageview is just being distributed more between the
main article and its redirect pages.

However our impression is that most pageviews come from search engine
results pages, and that wikilinks are not used very much.
See for instance the pageviews on redirects to [Red][red_redirects] and
[Black][black_redirects] (though one complication here is that
redirects might not be static, though in this case we wouldn't expect
the redirects to be changing much).
Likewise there are some effects that should push pageviews *less*
toward redirects.
For instance, presumably Google and other search engines have gotten
better at showing the link to the main article rather than a link to
the redirect page.

## Simple English Wikipedia


## Changes in pageview definition

See also [pageview definition changes][pageview_defn].
We don't think this is a big cause of pageview change.
It's also not clear whether pageview definitions are applied
retroactively.

# Further lines of exploration

This section lists various ideas for other explorations we did a bit of, or
considered doing but ran out of time for.

  * Comparison of Wikipedia pageviews for annual events close to the day of
    those events, and how those numbers have changed over the years (e.g.,
    traffic to the Black Friday page on Black Friday, etc.)
  * Comparison of traffic to the Wikipedia page of a news event relative to
    other objective measures of how "big" it became, to get a sense of the
    importance of Wikipedia in covering breaking news events
  * Weekday/weekend traffic variation on Wikipedia -- has Wikipedia weekday
    traffic changed over time differently than Wikipedia weekend traffic?
    Actually {weekday, weekend} × {desktop, mobile} × {now, earlier} so 2 × 2 ×
    2 = 8 combinations
  * Correlating changes to page size, quality, and editorial activity on pages
    to traffic to that page

# Acknowledgements

Thanks from Issa Rice to Vipul Naik for sponsoring Issa's work on this post.

Thanks from Vipul Naik to Issa Rice for writing an awesome post that puts the original post to shame.

# License

This post is released to the public domain. Note that linked or cited material need not be in the public domain.

# Appendix

## Data sources

### Data sources for total metrics

The Wikimedia Foundation publishes some of the pageview statistics for overall
pageviews data in places such as:

  * the ["Wikimedia project at a glance"][at_a_glance] page, which has a plot
    for the total pageviews on the English Wikipedia since 2008 (both of Erik
    Zachte's plots below come from this page)
  * the [Vital Signs dashboard][vital_signs], which is more interactive but
    only has pageviews data starting July 1, 2015
  * the [Wikipedia monthly combined chart][combined_table]

Other statistics for various overall growth can be found on the [Wikipedia
Statistics page][wikipedia_statistics], e.g. there is a page on the [size of
Wikipedia][size_of_wp].

### Data sources for page-level metrics

Pageviews data for specific pages can be accessed in the following forms:

  * Raw dumps are most consistently available in various datasets such as

      * pagecounts-raw (December 10, 2007 -- August 5, 2016), which only
        includes desktop pageviews and does not allow for identification of
        spiders
      * pagecounts-all-sites (September 23, 2014 -- August 5, 2016), which
        includes desktop as well as mobile pageviews but does not allow for
        identification of spiders
      * pageviews (starting May 1, 2015), which includes desktop as well as
        mobile pageviews and allows for identification of spiders, but only
        recently became available

    However all of these datasets are difficult to manage due to their large
    file sizes.

  * stats.grok.se, for desktop pageviews from December 10, 2007, through
    December 2015. 
    Note that stats.grok.se is [just a data visualizer][grok_faq].
    It uses pagecounts-raw, [which][pcr_email]:

    > was maintained by Domas Mituzas originally and taken over by the
    > analytics team.  It was and still is the most used dataset, though it has
    > some \[major\] problems.  It does not count access to the mobile site, it
    > does not filter out spider or bot traffic, and it suffers from unknown
    > loss due to logging infrastructure limitations.

    In other words, stats.grok.se uses an older dataset and [older definition
    of pageview][old_pv_defn] that does not do any bot or spider filtering.

  * The Wikimedia pageviews API, managed by the Wikimedia Foundation,
    and available since July 1, 2015.

We used pageview data from Wikipedia Views, that draws on the
following data sources:

  * stats.grok.se for desktop pageviews from December 2007 to December 2015.

  * The Wikimedia Pageview API for desktop user (human) pageviews from
    January 2016 to August 2016.

  * The Wikimedia Pageview API for desktop spider pageviews, mobile
    web pageviews, and mobile web spider pageviews, from July 2015 to
    August 2016.

### Other data sources for traffic and trends

  * comScore, both for overall data on Internet growth and for data on
    Wikipedia access.

  * Google Trends: We used this to explore some hypotheses that
    ultimately didn't pan out.
    For more on the Google Trends exports,
    see the [section in the plotting documentation][gt_plot_doc]

### Other sources

We conducted surveys circulated among audiences found through Google
Consumer Surveys, SurveyMonkey Audience, and our own survey
distribution mechanisms (sharing links via Facebook posts and groups).
These are discussed in the [Surveys](#surveys) section.

## Changes since the March 2015 post

This section explains in more detail the changes since the [March 2015 post][great_decline_full], and can be useful to people who have read that post.

## Availability of mobile data

The biggest change is the availability of mobile pageview data in an easily computable form.
Quoting from the [original post][great_decline_full]:

> Although the [mobile pageview] data is available, it’s not currently
> in an easily computable form, and I don’t currently have the time
> and energy to extract it. I’ll update this once the data on all
> pageviews since September 2014 is available on stats.grok.se or a
> similar platform.

The quoted section is referring to the release of pagecounts-all-sites
data (that includes mobile pageview data) starting September 23, 2014.
In principle, this data can be processed to extract mobile pageviews
starting that date.
However, it was too much work and Vipul had decided not to do it.

Now, things are different: the Wikimedia pageview API has mobile pageview data going back all the way to July 1, 2015.
So we have over a year of easily accessible mobile pageview data.
In particular, we now have an easy way of testing the validity of the hypothesis that desktop pageviews simply got shifted to mobile devices.

As before, we have decided not to process the dumps for the mobile pageview data from September 23, 2014 to June 30, 2015 to get mobile pageviews.
That's because we believe that the additional clarity it would give us wouldn't be worth the effort of processing those dumps.
Data before September 23, 2014 cannot be computed even in principle, because [raw server access logs are deleted after about two weeks][delete_log].

It will turn out that mobile traffic is significant, and the ratio of mobile to desktop traffic varies heavily by the type of page.
For more on the conclusions we drew based on the new mobile data, see [§ Shift to mobile](#shift-to-mobile).

## Bot and spider data

The new Wikimedia pageview API, starting July 1, 2015, allows for separate querying of the number of pageviews of a page by human users, bots, and spiders.
This is an improvement over the stats.grok.se data, which sums up human and bot pageviews.
By using the new data, we can not only get the true human pageviews starting July 1, 2015, but also extrapolate backward to estimate how much of the traffic reported in stats.grok.se earlier came from bots.

In principle, we can extract bot and spider traffic counts starting May 1, 2015, when the new pageviews dataset became available.
However, we decided that the extra information revealed from the extra two months of data wasn't enough to justify the effort of processing the dumps.

It will turn out that bot traffic is nonnegligible, but does not affect the big-picture conclusion much.
For more on the conclusions we draw, see [§ Non-human traffic](#non-human-traffic).

## Surveys and the human dimension

We conducted surveys using SurveyMonkey (both SurveyMonkey Audience
and our own weblink distribution) and Google Consumer Surveys.
We've documented the entirety of the surveys in [§ Surveys](#surveys).
We have also discussed specific conclusions from the survey response
in the context of hypotheses to which they are relevant, throughout the post.

## Graphs and visual aids

In the LessWrong version of the original post, [Strilanc commented][stri_com]:

> Could you convert the tables into graphs, please? It's much harder to see
> trends in lists of numbers.

We now have illuminative graphs in the post, as well as a link to many more
graphs, and full code to generate those graphs and other variants.

## Much more thorough research

The original post was written by just one of us (Vipul) over half a weekend, followed by a few hours of edits.

In contrast, for this post, we spent over 100 hours of our combined time examining all the evidence and questioning each other's thought processes.

Our research yielded useful by-products such as the [timeline of Wikimedia analytics][ana].

## Pageview plots

We plotted the $\log_{10}$ pageviews from December 2007 to August 2016 by
varying each of the following parameters.
All of the plots are [listed in a directory][plots_all].
In addition, all of the code used to generate the plots are in a [GitHub
repository][gh_plots_repo].

Pick one option from each of the following bullet points to arrive at a single
plot.

  * Tag-language combination; 16 in all.
    This is the beginning of the filename.
    Note that we inherit the term "tag" from Wikipedia Views.
    All the tag names can be seen on the ["Multiple tags and
    months"][multi_tag_month_wv] page.
    To see the Wikipedia pages that comprise the tag, click on the tag name,
    then click
    "Submit" to submit a sample query.
    In the resulting page, there is a table with a column called "Tag name";
    click the linked tag name to obtain a table with more columns -- one for
    each Wikipedia page in the tag.
  * Access method and agent: desktop, mobile, desktop + mobile (called
    "total"), desktop + mobile + spiders (called "total\_spider"); 4 in all.
    This comes after the tag-language combination in the filename.
  * All the pages in the tag or just the top 10 and total trend; 2 in all.
    Note that if a tag contains at most 10 pages, the top 10 plot and the plot
    with all the pages will be identical.
    This comes after the access method and agent combination in the filename,
    and is indicated by "top" is it is a top 10 plot and is empty otherwise.
  * Rolling mean (moving average) with window size $n$ months,
    for $n = 1, 3, 6, 12$, where
    $n = 1$ means just the normalized pageview plot; 4 in all.
    This is the last part of the filename besides the extension.
    The rolling mean is intended to smooth out noise, but also makes
    transitions harder to detect.
    For each month, the rolling mean is calculated as follows:
    the pageviews of $n$ months, starting with the current month and going
    backwards in time, are added
    together and then divided by the number of days during this period.
    One consequence of this is that even when $n=1$, the pageviews shown are
    not the raw pageviews for that month, but rather are normalized using the
    number of days in that month.
    It is the $\log_{10}$ of this value that is then taken and plotted.

There are 16 × 4 × 2 × 4 = 512 plots in all.

For example, the file [`americanpundits_total_top_3.png`][pundits_img] would be
the
pageviews for the "American television and radio pundits" tag, for desktop +
mobile (no spiders), with a rolling mean of window size $n = 3$ months, and
only the top 10 pages in the tag.

To visualize the "decline" in pageviews we plotted the pageviews from Wikipedia
Views, which now includes mobile data since July 2015.

In all of the plots, the vertical lines mean the following things:

  * Blue: July 2015, when mobile pageviews were introduced.
    This is only shown in plots with mobile data.
  * Green: $n-1$ months after July 2015, where $n$ is the window size
    of the rolling mean.
    This is only shown in plots with mobile data.
    In other words, this marks the *end of the transition* of including mobile
    data; after this line all the months used to calculate the rolling mean
    have mobile pageviews in them.
  * Red: January 2016, when the pageviews data for desktop pageviews
    switches from stats.grok.se to the Wikimedia Pageview API.
  * Yellow: $n-1$ months after January 2016, where $n$ is the window size of
    the rolling mean.
    In other words, this marks the *end of the transition* of switching to the
    Wikimedia Pageview API; after this line all the months used to calculate
    the rolling mean use only the Wikimedia Pageview API data.

In addition, the horizontal blue line marks the *top quartile for the totals
plot*, i.e. the line above which the top fourth of the data lie.

The trend lines colors for the colors tag *do not* match the colors they
represent.

Example:

![Plot for top 10 musicians, total access](http://ram.issarice.com/~issa/pageview_plots/musicians_total_top_6.png)

Another example:

![Plot for colors in English, desktop, window size of 12 months](http://ram.issarice.com/~issa/pageview_plots/colors_desktop_12.png)

Note that a drop from ~4.3 to ~3.9 on a $\log_{10}$ scale corresponds to a drop
from $10^{4.3} \approx 20{,}000$ to $10^{3.9} \approx 8{,}000$ in terms of
actual pageviews, i.e. a 60% drop.

The desktop-only plots generally show that desktop pageviews according
to stats.grok.se fell from around 2011 or 2013 (depending on the class
of pages examined) to 2015.
Adding on the Wikimedia Pageview API data for desktop from January 2016 to the
present shows that this trend seems to continue.

Note that in the main post, we only plot single-month graphs, rather than rolling means.
That is to keep the post simple and accessible.
If you choose to use the rolling means for analysis, then keep in mind that any bump becomes more gradual the longer you choose the window size for your rolling mean.

## Surveys

This section gives an overview of the surveys and lists the questions for each
survey for reference.
Since both the plots and the surveys were used to test various hypotheses about
the "great decline", the actual discussions about the survey results are
separately embedded in the various discussions about these hypotheses.

The surveys include:

  * A Google Consumer Surveys survey of a US audience (without any demographic
    filters)
    asking people to compare how much their Wikipedia
    usage has changed since 2011.
    This was answered by 1036 people.
    You can see the [results page][gcs_results].
    Note that for this survey, we had to shorten the responses from what they
    were originally due to Google Consumer Surveys' response character limits.
  * A SurveyMonkey US Audience survey (again, no demographic filters) asking
    the same question
    as the Google Consumer Surveys survey, plus some other background and
    follow-up questions.
    We ran this for 50 people and TODO answered.
    After this, we changed the order of the questions to ask about Wikipedia
    first, then about general internet use and use of search engines.
    We ran this second version for 50 people and TODO answered.
  * Vipul's timeline (first version)
  * UW audience (which version?)
  * More audiences?

### Google Consumer Surveys survey

This survey had a single question:

 1. How does your use of Wikipedia, the online encyclopedia, compare to your use
    5 years ago (2011)?
      * don't use now; didn't use in 2011
      * use now; didn't use in 2011
      * don't use now; used in 2011
      * use now; used in 2011 (to similar extent)
      * use now; used in 2011 (much more now)
      * use now; used in 2011 (much less now)
      * Other (please specify)

Since this was a Google Consumer Surveys survey, the respondent was also given
the options "Show me a different question" and "Skip survey" below the question
above.

The [survey results][gcs_results] are available.

### SurveyMonkey first survey (internet first)

Note that there is more logic to this survey than a simple list: questions
6 and 7 were only shown if the respondent indicated that their Wikipedia
use changed since 2011 in question 3; if they said more, they were shown
question 6 and if they said less, they were shown question 7 (which was
numbered question 6 for these people).

None of the multiple-choice options were randomized. (TODO: verify.)

A [dummy/mock-up version of the survey][dummy_sm_1] is available.

1.  How does your use of the Internet compare to your use 5 years ago (2011)?
      * don't use now; didn't use in 2011
      * use now; didn't use in 2011
      * don't use now; used in 2011
      * use now; used in 2011 (to similar extent)
      * use now; used in 2011 (much more now)
      * use now; used in 2011 (much less now)
2.  How does your use of search engines (Google search) compare to your
    use 5 years ago (2011)?
      * don't use now; didn't use in 2011
      * use now; didn't use in 2011
      * don't use now; used in 2011
      * use now; used in 2011 (to similar extent)
      * use now; used in 2011 (much more now)
      * use now; used in 2011 (much less now)
3.  How does your use of Wikipedia, the online encyclopedia, compare to
    your use 5 years ago (2011)?
      * don't use now; didn't use in 2011
      * use now; didn't use in 2011
      * don't use now; used in 2011
      * use now; used in 2011 (to similar extent)
      * use now; used in 2011 (much more now)
      * use now; used in 2011 (much less now)
4.  Do you have any thoughts on why this is the case for you?
      * Free response
5.  How do you mainly access Wikipedia?
      * Browser on desktop or laptop computer
      * Browser on mobile device
      * A specialized Wikipedia app
6.  You said that you use Wikipedia more now than in 2011. You also gave
    suggestions as to why. Here are some other reasons we've thought about
    that might not have occurred to you. Please select any that apply to you.
      * I didn't even have Internet access back then
      * I go to school now and I didn't before
      * I just use the Internet more
      * I think Wikipedia is more reliable now than it used to be
      * Wikipedia has more relevant content for me now
      * I just select whatever is at the top (or near the top) of search
        engine results, and I guess Wikipedia is showing up more
      * Other (please specify)
7.  You said that you use Wikipedia less now than in 2011. You also gave
    suggestions as to why. Here are some other reasons we've thought about that
    might not have occurred to you. Please select any that apply to you.
      * Google Knowledge cards
      * I use tools like Apple's Siri to access data from Wikipedia without
        reading it directly
      * I just select whatever is at the top (or near the top) of search
        engine results, and I guess Wikipedia is showing up less
      * I'm just generally more knowledgeable so I don't need as much
        encyclopedic information
      * Wikipedia seems to have less relevant content for me; I use other
        websites/wikis more now
      * Wikipedia's quality has decreased so it's not as good now
      * I now think Wikipedia is less reliable as a source of information
      * I'm not in school anymore
      * I use the Internet less in general
      * Other (please specify)

### SurveyMonkey second survey (Wikipedia first)

For this survey, the Wikipedia questions were asked first, and then the
more general internet and search engine questions.
Questions 4 and 5 were only shown when the respondent indicated that they
had changed their Wikipedia use since 2011; if more, the respondent
was shown question 4 and if less they were shown question 5.
All respondents then proceeded to question 6.

None of the multiple-choice options were randomized. (TODO: verify.)

A [dummy/mock-up version of the survey][dummy_sm_2] is available.

1.  How does your use of Wikipedia, the online encyclopedia, compare to your
    use 5 years ago (2011)?
      * don't use now; didn't use in 2011
      * use now; didn't use in 2011
      * don't use now; used in 2011
      * use now; used in 2011 (to similar extent)
      * use now; used in 2011 (much more now)
      * use now; used in 2011 (much less now)
2.  Do you have any thoughts on why this is the case for you?
      * Free response
3.  How do you mainly access Wikipedia?
      * Browser on desktop or laptop computer
      * Browser on mobile device
      * A specialized Wikipedia app
4.  You said that you use Wikipedia more now than in 2011. You also gave
    suggestions as to why. Here are some other reasons we've thought about
    that might not have occurred to you. Please select any that apply to you.
      * I didn't even have Internet access back then
      * I go to school now and I didn't before
      * I just use the Internet more
      * I think Wikipedia is more reliable now than it used to be
      * Wikipedia has more relevant content for me now
      * I just select whatever is at the top (or near the top) of search
        engine results, and I guess Wikipedia is showing up more
      * Other (please specify)
5.  You said that you use Wikipedia less now than in 2011. You also gave
    suggestions as to why. Here are some other reasons we've thought about that
    might not have occurred to you. Please select any that apply to you.
      * Google Knowledge cards
      * I use tools like Apple's Siri to access data from Wikipedia without
        reading it directly
      * I just select whatever is at the top (or near the top) of search
        engine results, and I guess Wikipedia is showing up less
      * I'm just generally more knowledgeable so I don't need as much
        encyclopedic information
      * Wikipedia seems to have less relevant content for me; I use
        other websites/wikis more now
      * Wikipedia's quality has decreased so it's not as good now
      * I now think Wikipedia is less reliable as a source of information
      * I'm not in school anymore
      * I use the Internet less in general
      * Other (please specify)
6. How does your use of the Internet compare to your use 5 years ago (2011)?
      * don't use now; didn't use in 2011
      * use now; didn't use in 2011
      * don't use now; used in 2011
      * use now; used in 2011 (to similar extent)
      * use now; used in 2011 (much more now)
      * use now; used in 2011 (much less now)
7.  How does your use of search engines (Google search) compare to your use 5
    years ago (2011)?
      * don't use now; didn't use in 2011
      * use now; didn't use in 2011
      * don't use now; used in 2011
      * use now; used in 2011 (to similar extent)
      * use now; used in 2011 (much more now)
      * use now; used in 2011 (much less now)

## Misc


The stats.grok.se data (that is our data source for desktop views till
December 2015) counts everybody, human and bot alike, who accesses the
desktop Wikipedia (see the [Data sources](#data-sources) section for
more details).
In contrast, the new pageview API (that is our data source for all
mobile pageviews from July 2015 on and for desktop pageviews January
2016 on) separates humans from bots and spiders, so that we can better
understand what fraction of views are driven by bots.

Note that the Wikimedia Pageview API makes the distinction between "bot" and
"spider", but we couldn't find pages for which the "bot" traffic was nonzero,
so we simply excluded the pageviews identified as "bot"; as far as we know,
"spider" means "not human".

We ended up including these spider pageviews from January 2016 for both desktop
and mobile spiders, although it would have also made sense to include the
mobile spiders starting in July 2015.

We also noted that, during months for which we had data from both
sources (such as December 2015), the stats.grok.se pageviews fell
halfway between the desktop (human) pageviews and the total of desktop
and desktop spider pageviews reported by the Wikimedia API.
We think this is likely because of the various "infrastructure
logging" problems with the pagecounts-raw dataset that stats.grok.se
is based off of.


[ana]: https://meta.wikimedia.org/wiki/Research:Timeline_of_Wikimedia_analytics "“Research:Timeline of Wikimedia analytics”. Wikimedia Meta-wiki."
[at_a_glance]: https://stats.wikimedia.org/EN/SummaryEN.htm "“Wikimedia project at a glance”."
[aula_03]: http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.76.8657&rep=rep1&type=pdf
[black_redirects]: http://wikipediaviews.org/displayviewsformultipleyears.php?tag=Pages%20that%20redirect%20to%20Black&language=en&device=desktop&allyears=allyears
[combined_table]: https://stats.wikimedia.org/EN/TablesPageViewsMonthlyCombined.htm 
[comparing_global_local]: https://arxiv.org/abs/1308.1776 "Schreck, Berit; Kämpf, Mirko; Kantelhardt, Jan; Motzkau, Holgar. “Comparing the usage of global and local Wikipedias with focus on Swedish Wikipedia”."
[comscore_uniques]: http://reportcard.wmflabs.org/graphs/unique_visitors
[comscore_wmf_sep14]: https://commons.wikimedia.org/w/index.php?title=File:Wikimedia%27s_traffic_-_Unique_Visitor_data_from_comScore_(September_2014).pdf&page=3
[cover_summary]: https://github.com/vipulnaik/working-drafts/blob/master/contributor-lists/contributor-cover-summary.mediawiki "Vipul Naik. “Contributor cover summary”. Last updated September 20, 2016."
[ctr]: http://dl.acm.org/citation.cfm?doid=2641580.2641616 "Benjamin Mako Hill and Aaron Shaw. “Consider the Redirect: A Missing Dimension of Wikipedia Research”. 2014."
[delete_log]: http://security.stackexchange.com/questions/23543/what-user-information-does-wikipedia-retain-when-a-page-is-viewed "Question asked by user Strapakowsky. “What user information does Wikipedia retain when a page is viewed?” Information Security Stack Exchange. November 3, 2012."
[desktop_stats]: https://stats.wikimedia.org/EN/TablesPageViewsMonthly.htm "“Page Views for Wikipedia, Non-mobile site, Normalized”. Wikimedia. Retrieved November 2, 2016."
[dummy_sm_1]: https://www.surveymonkey.com/r/G88QDCM "“Web and Wikipedia usage changes over time”. SurveyMonkey."
[dummy_sm_2]: https://www.surveymonkey.com/r/G8XRZQY "“Wikipedia and Web usage changes over time”. SurveyMonkey."
[en_wikipedia_stats_by_country]: https://stats.wikimedia.org/wikimedia/squids/SquidReportPageViewsPerLanguageBreakdown.htm. "“Wikimedia Traffic Analysis Report - Page Views Per Wikipedia Language - Breakdown”. Wikimedia Statustics."
[gauge_popularity_online]: http://www.wikihow.com/Gauge-the-Popularity-of-a-Topic-Online "“How to Gauge the Popularity of a Topic Online”. wikiHow."
[gcs_results]: https://www.google.com/insights/consumersurveys/view?survey=2l5h5cssu4am3oferd32zcxaai&question=1&filter=&rw=1 "Vipul Naik and Issa Rice. “How does your use of Wikipedia, the online encyclopedia, compare to your use 5 years ago (2011)?” Google Consumer Surveys. September 20, 2016."
[gh_plots_repo]: https://github.com/riceissa/wikipedia-decline
[gkg_sel]: http://searchengineland.com/google-launches-knowledge-graph-121585 "Danny Sullivan. “Google Launches Knowledge Graph To Provide Answers, Not Just Links”. May 16, 2012. Search Engine Land."
[gkg_wiki]: https://en.wikipedia.org/wiki/Knowledge_Graph " “Knowledge Graph”. Wikipedia, the Free Encyclopedia."
[great_decline]: http://lesswrong.com/lw/lxc/the_great_decline_in_wikipedia_pageviews/ "Vipul Naik. “The great decline in Wikipedia pageviews (condensed version)”. March 27, 2015. LessWrong."
[great_decline_full]: http://vipulnaik.com/blog/the-great-decline-in-wikipedia-pageviews-full-version/ "“The great decline in Wikipedia pageviews (full version)”. Vipul Naik. March 25, 2015."
[grok_faq]: http://stats.grok.se/about "“Wikipedia article traffic statistics”. stats.grok.se. Retrieved September 27, 2016."
[gt_plot_doc]: https://github.com/riceissa/wikipedia-decline#exporting-google-trends-data
[mob_stats]: https://stats.wikimedia.org/EN/TablesPageViewsMonthlyMobile.htm "“Page Views for Wikipedia, Mobile site, Normalized”. Wikimedia. Retrieved September 27, 2016."
[msr_08]: http://research.microsoft.com/en-us/um/people/sdumais/cikm2008-headstails_final.pdf
[multi_tag_month_wv]: http://wikipediaviews.org/multipletagsandmonths.php "“Wikipedia Views: simultaneously do multiple tags and months”."
[ny]: https://en.wikipedia.org/wiki/New_York
[ny_disc]: https://en.wikipedia.org/wiki/Talk:New_York#Proposed_action_to_resolve_incorrect_incoming_links
[ny_state]: https://en.wikipedia.org/w/index.php?title=New_York_(state)&redirect=no
[old_pv_defn]: https://phabricator.wikimedia.org/diffusion/ANME/browse/master/pageviews/webstatscollector/pageview_definition.png
[opera]: https://lists.wikimedia.org/pipermail/analytics/2016-June/005247.html
[pageview_defn]: https://meta.wikimedia.org/wiki/Research:Page_view#Change_log "“Research:Page view” § Change log. Wikimedia Meta-wiki. Retrieved September 26, 2016."
[pcr_email]: https://lists.wikimedia.org/pipermail/analytics/2016-March/005060.html
[peak_gist]: https://gist.github.com/riceissa/c47656af388120f4b5bbc4eba1ffc5ab
[peak_ov]: https://gist.github.com/riceissa/213c5b0cb31f12746d713f6ec0790257
[plots_all]: http://ram.issarice.com/~issa/pageview_plots/
[pundits_img]: http://ram.issarice.com/~issa/pageview_plots/americanpundits_total_top_3.png
[red_redirects]: http://wikipediaviews.org/displayviewsformultipleyears.php?tag=Pages%20that%20redirect%20to%20Red&language=en&device=desktop&allyears=allyears
[redirect_spelling]: https://wikitech.wikimedia.org/wiki/Analytics/Data/Redirects#Other_spellings_covered_by_a_redirect_page "“Analytics/Data/Redirects - Wikitech”."
[search_behavior_change]: http://www.seobythesea.com/2010/05/google-studies-how-search-behavior-changes-when-searchers-are-faced-with-difficult-questions/
[sel_search_growth]: http://searchengineland.com/google-now-handles-2-999-trillion-searches-per-year-250247 "“Google now handles at least 2 trillion searches per year”. Danny Sullivan. May 24, 2016. Search Engine Land."
[sgs_black]: http://stats.grok.se/en/201205/Black
[similarweb_evolving]: https://www.similarweb.com/blog/part-3-the-evolving-data-story-around-wikipedia "Roy Hinkis. “Part 3 – The Evolving Data Story Around Wikipedia”. August 27, 2015. SimilarWeb."
[simple_colors]: http://wikipediaviews.org/displayviewsformultipleyears.php?tag=Colors&language=simple&device=desktop&allyears=allyears
[size_of_wp]: https://en.wikipedia.org/wiki/Wikipedia:Size_of_Wikipedia "“Wikipedia:Size of Wikipedia”. Wikipedia."
[stri_com]: http://lesswrong.com/lw/lxc/the_great_decline_in_wikipedia_pageviews/c718
[traffic_var_time]: http://www.wikihow.com/Understand-Your-Website-Traffic-Variation-with-Time "“How to Understand Your Website Traffic Variation with Time”. wikiHow."
[vital_signs]: https://analytics.wikimedia.org/dashboards/vital-signs/ "“Vital Signs”."
[wikipedia_statistics]: https://en.wikipedia.org/wiki/Wikipedia:Statistics "“Wikipedia:Statistics - Wikipedia, the free encyclopedia”."
